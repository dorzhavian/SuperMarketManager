#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "superMarket.h"

int initSuperMarket(SuperMarket* superMarket)
{
    if (superMarket == NULL) 
        return 0;
    printf("Enter market name: ");
    superMarket->superMarketName = getStrExactLength();
    if (superMarket->superMarketName == NULL)
        return 0;                                     
    superMarket->productsPointersArr = (Product**)malloc(sizeof(Product*)); 
    if (superMarket->productsPointersArr == NULL)
    {
        free(superMarket->superMarketName);
        return 0;                                    
    }
    superMarket->customersArr = (Customer*)malloc(sizeof(Customer));
    if (superMarket->customersArr == NULL)  
    {
        free(superMarket->superMarketName);
        free(superMarket->productsPointersArr);         
        return 0;                                  
    }
    superMarket->numOfProducts = 0;
    superMarket->numOfCustomers = 0;
    return 1;
}

void printAllProducts(const SuperMarket* superMarket)
{
    printf("\nThere are %d products\n", superMarket->numOfProducts);
    printf("%-20s %-20s %-20s %-10s %-20s %-15s\n",
        "Name", "Barcode", "Type", "Price", "Count In Stock", "Expiry Date");
    printf("--------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < superMarket->numOfProducts; i++)
        printProduct((superMarket->productsPointersArr)[i]);
    printf("\n");
}

void printSuperMarket(const SuperMarket* superMarket)
{
    printf("\nSuper Market Name: %s \n", superMarket->superMarketName);
    printAllProducts(superMarket);
    if (superMarket->numOfCustomers > 0)
        printAllCustomers(superMarket);
}

//customers
int addCustomer(SuperMarket* superMarket, const Customer* customer)
{
    superMarket->customersArr = (Customer*)safeRealloc(superMarket->customersArr, (superMarket->numOfCustomers + 1) * (sizeof(Customer)));
    if (superMarket->customersArr == NULL)
        return 0;         
    superMarket->customersArr[superMarket->numOfCustomers] = *customer;
    superMarket->numOfCustomers++;
    return 1;
}

void printAllCustomers(const SuperMarket* superMarket)
{
    printf("\nThere are %d customers.\nCustomers Details:\n-----------------\n", superMarket->numOfCustomers);
    for (int i = 0; i < superMarket->numOfCustomers; i++)
        printCustomer(&((superMarket->customersArr)[i]));
}

int isExistName(const char* customerName, const SuperMarket* superMarket)
{
    for (int i = 0; i < superMarket->numOfCustomers; i++)
    {
        if (strcmp(customerName, superMarket->customersArr[i].name) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int isExistID(const char* customerID, const SuperMarket* superMarket)
{
    for (int i = 0; i < superMarket->numOfCustomers; i++)
    {
        if (strcmp(customerID, superMarket->customersArr[i].id) == 0)
        {
            return 1;
        }
    }
    return 0;
}

//barcodes
size_t productIndexByBarcode(const SuperMarket* superMarket)
{
    char bcInput[MAX_LEN];
    printf("\nPlease enter a valid barcode of product in the shop.\nBarcode must be 7 length exactly.\nMust have 2 type prefix letters followed by a 5 digits number.\nFor Example: FR20301\n");
    checkValidBarcodeInput(bcInput);
    return findBarcode(superMarket, bcInput);
}

size_t findBarcode(const SuperMarket* superMarket, char* bcInput)
{
    for (size_t i = 0; i < superMarket->numOfProducts; i++)
    {
        if (strcmp(bcInput, superMarket->productsPointersArr[i]->barCode) == 0)
            return i;
    }
    return -1;    // if not found return -1
}

int uniqueBarcode(char* buffer, const SuperMarket* superMarket)	
{
    for (size_t j = 0; j < superMarket->numOfProducts; j++)
    {
        if (!(strcmp(buffer, superMarket->productsPointersArr[j]->barCode)))
        {
            return 0;
        }
    }
    return 1;
}

size_t indexWhoIsShopping(const SuperMarket* superMarket)
{
    char* choice;
    printAllCustomers(superMarket);
    printf("\nWho is shopping? (Enter customer ID): ");
    choice = getStrExactLength();			
    if (!choice)
    {
        return -1;
    }
    int res;
    res = isExistID(choice, superMarket);
    if (!res)
    {
        printf("\nThis customer not listed\n");
        free(choice);
        return -1;
    }
    size_t index = findIndexOfCustomer(superMarket, choice);				
    free(choice);
    return index;
}

//case 1: 
void updateProductQuantity(SuperMarket* superMarket)
{
    int addStock;
    size_t index = productIndexByBarcode(superMarket);
    if (index == -1)
        printf("No such product barcode in the super market.\n");
    else
    {
        do {
            printf("How many items you want to add to stock? ");
            scanf("%d", &addStock);
        } while (addStock <= 0);
        superMarket->productsPointersArr[index]->quantity += addStock;
        printf("Stock update Successfully!!\n");
    }
}

int addProductToSuperMarket(SuperMarket* superMarket)
{
    Product* pP = (Product*)malloc(sizeof(Product));
    if (!pP)
        return 0;          
    superMarket->productsPointersArr = (Product**)safeRealloc(superMarket->productsPointersArr, (superMarket->numOfProducts + 1) * sizeof(Product*));
    if (!superMarket->productsPointersArr)
    {
        free(pP);
        return 0;          
    }
    initProduct(pP);
    while (uniqueBarcode(pP->barCode, superMarket) == 0) {
        generateAndAddRandomDigits(pP->barCode);
    }
    superMarket->productsPointersArr[superMarket->numOfProducts] = pP;
    superMarket->numOfProducts++;
    return 1;
}

size_t findIndexOfCustomer(const SuperMarket* superMarket,const char* ID)
{
    for (size_t i = 0; i < superMarket->numOfCustomers; i++)
    {
        if(strcmp(superMarket->customersArr[i].id, ID) == 0)
            return i;
    }
    return -1;
}

//case 2:
void InitAndAddCustomer(SuperMarket* superMarket)
{
    Customer customer;
    int res;
    do {
        initCustomer(&customer);
        res = isExistID(customer.id, superMarket);
        if (res)
            printf("ID %s is not unique!\n", customer.id);
    } while (res);
    if (isExistName(customer.name, superMarket))
    {
        printf("This customer is already in market\nError adding customer\n");
        return;
    }
    res = addCustomer(superMarket, &customer);
    if (!res)
        free(superMarket->customersArr);
    printf("Customer added Successfully!!\n");
}

//case 3:
int possibleToShopping(const SuperMarket* superMarket)
{
    if (superMarket->numOfCustomers == 0)
    {
        printf("No customer listed to market\n");
        return 0;
    }
    else if (superMarket->numOfProducts == 0)
    {
        printf("No products in market - cannot shop!\n");
        return 0;
    }
    return 1;
}

int addOrUpdateShoppingCart(SuperMarket* superMarket, size_t indexProduct, size_t indexCustomer)
{
    size_t res3;
    res3 = itemIndexInCart(&(superMarket->customersArr[indexCustomer].cart), superMarket->productsPointersArr[indexProduct]->barCode);
    if (res3 != -1)
    {
        updateShoppingItemQuantityInCart(&(superMarket->customersArr[indexCustomer].cart), superMarket->productsPointersArr[indexProduct], res3);
    }
    else
    {
        res3 = addShoppingItemToCart(&(superMarket->customersArr[indexCustomer].cart), superMarket->productsPointersArr[indexProduct]);
        if (!res3)
            return 0;
    }
    return 1;
}

int shopping(SuperMarket* superMarket, size_t indexCustomer)
{
    size_t indexProduct;
    char choice;
    while (1)
    {
        printf("Do you want to shop for a product? y/Y, anything else to exit! ");
        scanf(" %c", &choice);
        if (tolower(choice) != 'y')
        {
            printf("---------- Shopping ended ----------\n");
            break;
        }
        indexProduct = productIndexByBarcode(superMarket);
        if (indexProduct != -1)
        {
            if (superMarket->productsPointersArr[indexProduct]->quantity == 0)
            {
                printf("This product out of stock\n");
                continue;
            }
            return (addOrUpdateShoppingCart(superMarket,indexProduct,indexCustomer));
        }
        else
            printf("No such product barcode\n");
    }
    return 1;
}

//case 5:
int buyAtTheSuperMarket(SuperMarket* superMarket, size_t customerIndex)
{
    char choice;
    printShoppingCart(&superMarket->customersArr[customerIndex].cart);
    printf("Do you want to pay for this cart? y/Y, anything else to cancel shopping!\n");
    scanf(" %c", &choice);
    if (tolower(choice) != 'y')
    {
        purchaseCanceled(superMarket, customerIndex);
        printf("!!! --- PURCHASE WAS CANCELED --- !!!\n");
    }
    else
    {
        printf("-----------------Cart info and bill for %s -----------------", superMarket->customersArr[customerIndex].name);
        printShoppingCart(&superMarket->customersArr[customerIndex].cart);
        printf("                 ____   _ __   ____  __ _____ _   _ _____                              \n"
           "                |  _ \\ / \\\\ \\ / /  \\/  | ____| \\ | |_   _|                             \n"
           "                | |_) / _ \\\\ V /| |\\/| |  _| |  \\| | | |                               \n"
           "                |  __/ ___ \\| | | |  | | |___| |\\  | | |                               \n"
           "                |_| /_/   \\_\\_|_|_|_ |_|_____|_|_\\_|_|_|  _____ ____  _____ _   _ _    \n"
           "                            / ___|| | | |/ ___/ ___/ ___|| ____/ ___||  ___| | | | |   \n"
           "                            \\___ \\| | | | |   \\___ \\___ \\|  _| \\___ \\| |_  | | | | |   \n"
           "                             ___) | |_| | |___ ___) |__) | |___ ___) |  _| | |_| | |___\n"
           "                            |____/ \\___/ \\____|____/____/|_____|____/|_|    \\___/|_____|\n");
        freeShoppingCart(&superMarket->customersArr[customerIndex].cart);
        return initShoppingCart(&superMarket->customersArr[customerIndex].cart);
    }
    return 1;
}

void purchaseCanceled(SuperMarket* superMarket, size_t customerIndex)
{
    for (size_t i = 0; i < superMarket->customersArr[customerIndex].cart.numOfSInCart; i++)
    {
        char* currBarcode = superMarket->customersArr[customerIndex].cart.shoppingItemsArr[i]->barCode;
        size_t productIndex = findBarcode(superMarket, currBarcode);
        superMarket->productsPointersArr[productIndex]->quantity += superMarket->customersArr[customerIndex].cart.shoppingItemsArr[i]->quantity;
    }
    freeShoppingCart(&superMarket->customersArr[customerIndex].cart);
    initShoppingCart(&superMarket->customersArr[customerIndex].cart);
}

//case 6:
void printAllProductsByType(const SuperMarket* superMarket)
{
    if (superMarket->numOfProducts == 0)
    {
        printf("No products in market!\n");
        return;
    }
    Type type = getProductType();
    size_t i;
    for (i = 0; i < superMarket->numOfProducts && superMarket->productsPointersArr[i]->theType != type; i++);     
    if (i == superMarket->numOfProducts)
    {
        printf("\nThere are no product of type %s in market %s\n", types[type], superMarket->superMarketName);
        return;
    }
    else {

        printf("\nAll products of type %s:\n---------------------------\n", types[type]);
        for (i = 0; i < superMarket->numOfProducts; i++)
        {
            if (superMarket->productsPointersArr[i]->theType == type)
                printProduct(superMarket->productsPointersArr[i]);
        }
    }
}

//free
void freeSuperMarket(SuperMarket* superMarket)
{
    free(superMarket->superMarketName);
    for (size_t i = 0; i < superMarket->numOfProducts; i++)
    {
        free(superMarket->productsPointersArr[i]);
    }
    free(superMarket->productsPointersArr);
    for (size_t j = 0; j < superMarket->numOfCustomers; j++)
    {
        freeCustomer(&superMarket->customersArr[j]);
    }
    free(superMarket->customersArr);
}

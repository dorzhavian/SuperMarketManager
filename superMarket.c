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
        return 0;                                     //REMEMBER TO FREE()!!!!!!!!!!!!!
    superMarket->productsPointersArr = (Product**)malloc(sizeof(Product*)); 
    if (superMarket->productsPointersArr == NULL)
    {
        free(superMarket->superMarketName);
        return 0;                                     // REMEMBER FREE() !!!!!!!!!!!!! 
    }
    superMarket->customersArr = (Customer*)malloc(sizeof(Customer));
    if (superMarket->customersArr == NULL)  
    {
        free(superMarket->superMarketName);
        free(superMarket->productsPointersArr);         
        return 0;                                   // REMEMBER FREE() !!!!!!!!!!!!! 
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

void printSuperMarket(SuperMarket* superMarket)
{
    printf("\nSuper Market Name: %s \n", superMarket->superMarketName);
    printAllProducts(superMarket);
    if (superMarket->numOfCustomers > 0)
        printAllCustomers(superMarket);
}

int addCustomer(SuperMarket* superMarket, const Customer* customer)
{
    superMarket->customersArr = (Customer*)safeRealloc(superMarket->customersArr, (superMarket->numOfCustomers + 1) * (sizeof(Customer)));
    if (superMarket->customersArr == NULL)
        return 0;         // REMEMBER TO FREE() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    superMarket->customersArr[superMarket->numOfCustomers] = *customer;
    superMarket->numOfCustomers++;
    return 1;
}

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

void updateProductQuantity(SuperMarket* superMarket)
{
    int index = productIndexByBarcode(superMarket);
    if (index == -1)
        printf("No such product barcode in the super market.\n");
    else
    {
        printf("How many items you want to add to stock? ");
        int addStock;
        scanf("%d", &addStock);
        superMarket->productsPointersArr[index]->quantity += addStock;
        printf("Stock update Successfully!!\n");
    }
}

//maybe not neccessery
void addNewProduct(SuperMarket* superMarket)
{
    int res = addProductToSuperMarket(superMarket);
    //if (!res)
    // 
        //free(superMarket->productsPointersArr);
    //else
        printf("\nProduct Added Successfully!!!\n");
}

int addProductToSuperMarket(SuperMarket* superMarket)
{
    Product* pP = (Product*)malloc(sizeof(Product));
    if (!pP)
        return 0;           // REMEMBER TO FREE() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    superMarket->productsPointersArr = (Product**)safeRealloc(superMarket->productsPointersArr, (superMarket->numOfProducts + 1) * sizeof(Product*));
    if (!superMarket->productsPointersArr)
    {
        free(pP);
        return 0;          // REMEMBER TO FREE() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    initProduct(pP);
    while (uniqueBarcode(pP->barCode, superMarket) == 0) {
        generateAndAddRandomDigits(pP->barCode);
    }
    superMarket->productsPointersArr[superMarket->numOfProducts] = pP;
    superMarket->numOfProducts++;
    return 1;
}

int productIndexByBarcode(SuperMarket* superMarket)
{
    char bcInput[MAX_LEN];
    printf("\nPlease enter a valid barcode of product in the shop.\nBarcode must be 7 length exactly.\nMust have 2 type prefix letters followed by a 5 digits number.\nFor Example: FR20301\n");
    checkValidBarcodeInput(bcInput);
    return findBarcode(superMarket, bcInput);
}

int findBarcode(const SuperMarket* superMarket, char* bcInput)
{
    for (int i = 0; i < superMarket->numOfProducts; i++)
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

void printAllCustomers(SuperMarket* superMarket)
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

int buyAtTheSuperMarket(SuperMarket* superMarket, int customerIndex)
{
    char choice;
    printShoppingCart(&superMarket->customersArr[customerIndex].cart);
    printf("Do you want to pay for this cart? y/Y, anything else to cancel shopping!\n");
    scanf(" %c", &choice);
    if (tolower(choice) != 'y')
    {
        /// CREATE METHODS THAT FREE THE WHOLE CART, UPDATE THE QUANTITY OF THE ORIGINAL PRODUCTS AT SUPER AND INITSHOPPINGCART!!!!!! , IF THIS METHOD USE MALLOC STAY INT IF NOT VOID!!!!!!
        printf("!!! --- PURCHASE WAS CANCELED --- !!!\n");
    }
    else
    {
        printf("-----------------Cart info and bill for %s -----------------", superMarket->customersArr[customerIndex].name);
        printShoppingCart(&superMarket->customersArr[customerIndex].cart);
        printf("!!! --- PAYMENT RECIVED --- !!!\n");
        /// JUST INITSHOPPINGCART HERE FOR THIS CUSTOMER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    return 1;
}

void freeSuperMarket(SuperMarket* superMarket)
{

}

int findIndexOfCustomer(const SuperMarket* superMarket,const char* ID)
{
    for (int i = 0; i < superMarket->numOfCustomers; i++)
    {
        if(strcmp(superMarket->customersArr[i].id, ID) == 0)
            return i;
    }
    return -1;
}


void printAllProductsByType(SuperMarket* superMarket)
{
    if (superMarket->numOfProducts == 0)
    {
        printf("No products in market!\n");
        return;
    }
    Type type = getProductType();
    size_t i;
    for (i = 0; i < superMarket->numOfProducts && superMarket->productsPointersArr[i]->theType != type; i++);     // fast for - check if exist products of the current type
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
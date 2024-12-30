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


void printSuperMarket(const SuperMarket* superMarket)
{
    printf("Super Market Name: %s \n", superMarket->superMarketName);
    printf("There are %d products\n", superMarket->numOfProducts);
    printf("%-20s %-20s %-20s %-10s %-20s %-15s\n",
        "Name", "Barcode", "Type", "Price", "Count In Stock", "Expiry Date");
    printf("--------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < superMarket->numOfProducts; i++)
        printProduct((superMarket->productsPointersArr)[i]);
    if (superMarket->numOfCustomers > 0)
        printAllCustomers(superMarket);
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

int addCustomer(SuperMarket* superMarket, const Customer* customer)
{
    superMarket->customersArr = (Customer*)safeRealloc(superMarket->customersArr, (superMarket->numOfCustomers + 1) * (sizeof(Customer)));
    if (superMarket->customersArr == NULL)
        return 0;         // REMEMBER TO FREE() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    superMarket->customersArr[superMarket->numOfCustomers] = *customer;
    superMarket->numOfCustomers++;
    return 1;
}

int buyAtTheSuperMarket()
{
    return 0;
}

void printAllProductsByType(SuperMarket* superMarket, Type type)
{

}

int isProductExistByBarcode(const SuperMarket* superMarket, char* bcInput)
{
    for (int i = 0; i < superMarket->numOfProducts; i++)
    {
        if (strcmp(bcInput, superMarket->productsPointersArr[i]->barCode) == 0)
            return i;
    }
    return -1;
}


void freeSuperMarket(SuperMarket* superMarket)
{

}


int uniqueBarcode(char* buffer, const SuperMarket* superMarket)				//added
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

void printAllCustomers(const SuperMarket* superMarket)
{
    printf("\nThere are %d customers\n", superMarket->numOfCustomers);
    for (int i = 0; i < superMarket->numOfCustomers; i++)
        printCustomer(&((superMarket->customersArr)[i]));
}

#include <stdio.h>
#include "superMarket.h"

int initSuperMarket(SuperMarket* superMarket)
{
    return 0;
}

void printSuperMarket(const SuperMarket* superMarket)
{
    printf("Super Market Name: %s \n", superMarket->superMarketName);
    printf("There are %d products\n", superMarket->numOfProducts);
    printf("Name                 Barcode       Type                 Price      Count In Stoke       Expiry Date\n");
    printf("----------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < superMarket->numOfProducts; i++)
        printProduct((superMarket->productsPointersArr)[i]);
}

int addProductToSuperMarket(SuperMarket* superMarket, Product* product)
{
    return 0;
}

int addCustomer(SuperMarket* superMarket, const Customer* customer)
{
    return 0;
}

int buyAtTheSuperMarket()
{
    return 0;
}

void printAllProductsByType(SuperMarket* superMarket, Type type)
{

}
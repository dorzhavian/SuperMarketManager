#pragma once

#include "customer.h"
#include "product.h"

typedef struct {
	char* superMarketName;
	Customer* customersArr;
	int numOfCustomers;
	Product** productsPointersArr;
	int numOfProducts;
}SuperMarket;

int initSuperMarket(SuperMarket* superMarket);
void printSuperMarket(const SuperMarket* superMarket);
int addProductToSuperMarket(SuperMarket* superMarket, Product* product);
int addCustomer(SuperMarket* superMarket, const Customer* customer);
int buyAtTheSuperMarket();
void printAllProductsByType(SuperMarket* superMarket, Type type);

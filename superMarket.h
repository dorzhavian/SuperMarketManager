#pragma once

#include "customer.h"
#include "product.h"
#include "functions.h"


typedef struct {
	char* superMarketName;
	Customer* customersArr;
	int numOfCustomers;
	Product** productsPointersArr;
	int numOfProducts;
}SuperMarket;

int initSuperMarket(SuperMarket* superMarket);

void printSuperMarket(const SuperMarket* superMarket);

int addProductToSuperMarket(SuperMarket* superMarket);

int addCustomer(SuperMarket* superMarket, const Customer* customer);

int buyAtTheSuperMarket();

void printAllProductsByType(SuperMarket* superMarket, Type type);

int isProductExistByBarcode(const SuperMarket* superMarket, char* bcInput);

void freeSuperMarket(SuperMarket* superMarket);

int uniqueBarcode(char* buffer, const SuperMarket* superMarket);

void printAllCustomers(const SuperMarket* superMarket);

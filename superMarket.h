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

void printAllProducts(const SuperMarket* superMarket);

void printSuperMarket(SuperMarket* superMarket);

int addProductToSuperMarket(SuperMarket* superMarket);

int addCustomer(SuperMarket* superMarket, const Customer* customer);

int buyAtTheSuperMarket(SuperMarket* superMarket, int customerIndex);

int findBarcode(const SuperMarket* superMarket, char* bcInput);

void freeSuperMarket(SuperMarket* superMarket);

int uniqueBarcode(char* buffer, const SuperMarket* superMarket);

void printAllCustomers(SuperMarket* superMarket);

int productIndexByBarcode(SuperMarket* superMarket);

//added2
int isExistName(const char* customer, const SuperMarket* superMarket);

int isExistID(const char* customer, const SuperMarket* superMarket);

void InitAndAddCustomer(SuperMarket* superMarket);

//addOrUpdateProductToSuperMarket();

void updateProductQuantity(SuperMarket* superMarket);

void addNewProduct(SuperMarket* superMarket);
//till here

int findIndexOfCustomer(const SuperMarket* superMarket,const char* ID);

//case 6:

void printAllProductsByType(SuperMarket* superMarket);


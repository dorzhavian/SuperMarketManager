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

void printSuperMarket(const SuperMarket* superMarket);

//customers
int addCustomer(SuperMarket* superMarket, const Customer* customer);

int isExistName(const char* customer, const SuperMarket* superMarket);

int isExistID(const char* customer, const SuperMarket* superMarket);

void printAllCustomers(const SuperMarket* superMarket);

size_t indexWhoIsShopping(const SuperMarket* superMarket);


//barcodes
size_t findBarcode(const SuperMarket* superMarket, char* bcInput);

int uniqueBarcode(char* buffer, const SuperMarket* superMarket);

size_t productIndexByBarcode(const SuperMarket* superMarket);


//case 1:
void updateProductQuantity(SuperMarket* superMarket);

int addProductToSuperMarket(SuperMarket* superMarket);

size_t findIndexOfCustomer(const SuperMarket* superMarket, const char* ID);

//case 2:
void InitAndAddCustomer(SuperMarket* superMarket);

//case 3:
int possibleToShopping(const SuperMarket* superMarket);

int addOrUpdateShoppingCart(SuperMarket* superMarket, size_t indexProduct, size_t indexCustomer);

int shopping(SuperMarket* superMarket, size_t indexCustomer);

//case 5:
int buyAtTheSuperMarket(SuperMarket* superMarket, size_t customerIndex);

void purchaseCanceled(SuperMarket* superMarket, size_t customerIndex);

//case 6:
void printAllProductsByType(const SuperMarket* superMarket);

//free
void freeSuperMarket(SuperMarket* superMarket);

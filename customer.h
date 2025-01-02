#pragma once


#include "shoppingCart.h"
#include "functions.h"
//#include "superMarket.h"		//???

#define ID_LEN 10

#define MAX_LEN 255

typedef struct {
	char id[ID_LEN];
	char* name;						//REMEMBER TO FREE()!!!!!!!!!!
	ShoppingCart cart;              // CHECK IF MAKE A POINTER 
} Customer;


int initCustomer(Customer* customer);

void printCustomer(const Customer* customer);

void initId(Customer* customer);

int initFirstName(char** firstName);

int initLastName(char** lastName);

void mergeIntoFullName(Customer* customer, char* firstName, char* lastName);

int initFullName(Customer* customer);

void freeCustomer(Customer* customer);   // use freeShoppingCart for each seller
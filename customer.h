#pragma once

#define ID_LEN 10

#define MAX_LEN 255

typedef struct {
	char id[ID_LEN];
	char name[MAX_LEN];
	//ShoppingCart cart;
} Customer;


int initCustomer(Customer* customer);

void printCustomer(const Customer* customer);

void initId(Customer* customer);

int initName(Customer* customer);

void freeCustomer(Customer* customer);   // use freeShoppingCart for each seller
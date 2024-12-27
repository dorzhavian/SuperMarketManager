#pragma once

#define ID_LEN 10

typedef struct {
	char id[ID_LEN];
	char* name;
	//ShoppingCart cart;
} Customer;


int initCustomer(Customer* customer);

void printCustomer(const Customer* customer);

void initId(Customer* customer);

int initName(Customer* customer);

// void freeCustomer(Customer* customer) - REMEMBER TO FREE EVERY PLACE THAT USED MALLOC;
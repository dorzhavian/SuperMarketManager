#pragma once

#define ID_LEN 10

typedef struct {
	char id[ID_LEN];
	char* name;
	//ShoppingCart cart;
} Customer;


int initCustomer(Customer* customer);

void printCustomer(const Customer* customer);

int initId(Customer* customer);

void initName();
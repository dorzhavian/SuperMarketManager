#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "customer.h"
#include "functions.h"

#define MAX_LEN 255


int initCustomer(Customer* customer) {
	int res;
	initName(customer);
	initId(customer);
	res = initShoppingCart(&customer->cart);
	if (!res) 
		free(&customer->cart);
	return res;
}


void initName(Customer* customer) 
{
	char firstName[MAX_LEN];
	char lastName[MAX_LEN];
	printf("Enter first name: \n");
	do {
		myGets(firstName, MAX_LEN);
	} while (!firstName);
	printf("Enter last name: \n");
	do {
		myGets(lastName, MAX_LEN);
	} while (!lastName);
	fixNameStr(firstName);
	fixNameStr(lastName);
	strcpy(customer -> name, firstName);
	strcat(customer -> name, " - ");
	strcat(customer -> name, lastName);
	strcat(customer -> name, "\0");
}

void freeCustomer(Customer* customer)
{

}

void initId(Customer* customer) 
{
	char temp[MAX_LEN] = { 0 };
	size_t len;
	int ifOnlyDigits;
	printf("Please enter valid ID, should be 9 digits.\nFor example: 123456789\n");
	do {
		scanf("%s", temp);
		len = strlen(temp);
		ifOnlyDigits = isNumericString(temp);
		if (len != ID_LEN - 1 || !ifOnlyDigits)
			printf("Please enter 9 digits!\nFor example: 123456789\n");
	} while ((len != ID_LEN - 1) || (!ifOnlyDigits));
	strcpy(customer->id, temp);
}

int isExistID()
{
	return 0;
}

int isExistName()
{
	return 0;
}

void printCustomer(const Customer* customer) {
	printf("Customer Details:\n");
	printf("-----------------\n");
	printf("Name: %s\n", customer->name);
	printf("Id: %s\n", customer->id);

}

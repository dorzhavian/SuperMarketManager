#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "Customer.h"
#include "functions.h"

#define MAX_LEN 255


int initCustomer(Customer* customer) {
	int res;
	res = initName(customer);
	initId(customer);
	return res;
}


int initName(Customer* customer) 
{
	char* firstName = {0};
	char* lastName = {0};
	printf("Enter first name: \n");
	do {
		myGets(firstName, MAX_LEN);
		if (!firstName);
			printf("Invalid input! Please try again.");
	} while (!firstName);
	printf("Enter last name: \n");
	do {
		myGets(lastName, MAX_LEN);
		if (!lastName)
			printf("Invalid input! Please try again.");
	} while (!lastName);
	fixNameStr(firstName);
	fixNameStr(lastName);
	strcpy(customer -> name, firstName);
	strcat(customer -> name, " - ");
	strcat(customer -> name, lastName);
	strcat(customer -> name, "\0");
	return 1;
}

void freeCustomer(Customer* customer)
{

}

void initId(Customer* customer) 
{
	char temp[MAX_LEN] = { 0 };
	size_t len;
	int ifOnlyDigits;
	printf("Please enter valid ID: \n");
	do {
		scanf("%s", temp);
		len = strlen(temp);
		ifOnlyDigits = isNumericString(temp);
		if (len != ID_LEN - 1)
			printf("Please enter 9 digits!");
	} while ((len != ID_LEN - 1) || (!ifOnlyDigits));
	strcpy(customer->id, temp);
}


void printCustomer(const Customer* customer) {
	printf("Customer Details:\n");
	printf("-----------------\n");
	printf("Name: %s\n", customer->name);
	printf("Id: %s\n", customer->id);

}

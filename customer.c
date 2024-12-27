#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "Customer.h"
#include "general.h"

#define MAX_LEN 255


int initCustomer(Customer* customer) {
	int res;
	res = initName(customer);
	initId(customer);
	return res;
}


int initName(Customer* customer) 
{
	char* firstName;
	char* lastName;
	size_t len;

	printf("Enter first name: \n");
	do {
		firstName = getStrExactLength();
		if (!firstName) {
			printf("Memory allocation failed.\n");
			return 0;
		}
		len = strlen(firstName);
		if (len == 0) 
			printf("Invalid input! Please try again.");
	} while (len == 0);
	printf("Enter last name: \n");
	do {
		lastName = getStrExactLength();                       
		if (!lastName) {
			printf("Memory allocation failed.\n");
			free(firstName);                                        
			return 0;
		}
		len = strlen(lastName);
		if (len == 0)
			printf("Invalid input! Please try again.");
	} while (len == 0);
	fixNameStr(firstName);
	fixNameStr(lastName);
	size_t fullNameLength = strlen(firstName) + strlen(lastName) + 4; 
	customer -> name = malloc(fullNameLength);
	if (customer-> name == NULL) {
		printf("Memory allocation failed.\n");
		free(lastName);
		free(firstName);
		return 0;
	}
	strcpy(customer -> name, firstName);
	strcat(customer -> name, " - ");
	strcat(customer -> name, lastName);
	strcat(customer -> name, "\0");
	free(lastName);
	free(firstName);
    // FREE() customer -> name remember !!!!!!
	return 1;
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

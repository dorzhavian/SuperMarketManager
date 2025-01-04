#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "customer.h"

#define MAX_LEN 255


int initCustomer(Customer* customer) {
	int res;
	initFullName(customer);
	initId(customer);
	res = initShoppingCart(&customer->cart);
	//why????
    if (!res) 
		free(&customer->cart);
	return res;
}

int initFirstName(char** firstName)             //Call by reference
{
    size_t len;
    printf("Enter first name: \n");
    do {
        *firstName = getStrExactLength();
        if (!(*firstName)) {
            //printf("Memory allocation failed.\n");
            return 0;
        }
        len = strlen(*firstName);
        if (len == 0)
            printf("Invalid input! Please try again.");
    } while (len == 0);
    fixNameStr(*firstName);
    return 1;
}

int initLastName(char** lastName)           //Call by reference
{
    size_t len;
    printf("Enter last name: \n");
    do {
        *lastName = getStrExactLength();
        if (!(*lastName)) {
            printf("Memory allocation failed.\n");
            return 0;
        }
        len = strlen(*lastName);
        if (len == 0)
            printf("Invalid input! Please try again.");
    } while (len == 0);
    fixNameStr(*lastName);
    return 1;
}

void mergeIntoFullName(Customer* customer, char* firstName, char* lastName)
{
    strcpy(customer->name, firstName);
    strcat(customer->name, " - ");
    strcat(customer->name, lastName);
    strcat(customer->name, "\0");
}

int initFullName(Customer* customer)
{
    int res;
    char* firstName;
    char* lastName;
    res = initFirstName(&firstName);
    if (!res)
        return 0;           //REMEMBER TO FREE()!!!!!//
    res = initLastName(&lastName);
    if (!res)
    {
        free(firstName);
        return 0;
    } 
    size_t fullNameLength = strlen(firstName) + strlen(lastName) + 4;
    customer->name = malloc(fullNameLength);
    if (customer->name == NULL) {
        //printf("Memory allocation failed.\n");
        free(lastName);
        free(firstName);
        return 0;
    }
    mergeIntoFullName(customer, firstName, lastName);
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


void printCustomer(Customer* customer) {
	printf("Name: %s\n", customer->name);
	printf("Id: %s\n", customer->id);
    /*
    if (customer->cart.numOfSInCart == 0)
        printf("Shopping cart is empty!\n\n");
    else {
        printShoppingCart(&customer->cart);
    }
    */
}

void freeCustomer(Customer* customer)
{
    free(customer->name);
    freeShoppingCart(&customer->cart);
}

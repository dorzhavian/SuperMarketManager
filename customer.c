#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Customer.h"
#include "general.h"
#define MAX_CHAR 255


int initCustomer(Customer* customer) {
	int res;
	do
	{
		res = initId(customer);
	} while (!res);

	initName(customer);


}


void initName(Customer* customer) {

	char* finalName;
	char firstName[MAX_CHAR];
	char lastName[MAX_CHAR];

	printf("Enter first name: \n");
	myGets(firstName, MAX_CHAR);

	printf("Enter last name: \n");
	myGets(lastName, MAX_CHAR);


}



int initId(Customer* customer) {

	char temp[MAX_CHAR] = { 0 };
	printf("Please enter Id\n");
	scanf("%s", temp);

	if (strlen(temp) != ID_LEN - 1) {
		return 0;

	}
	for (int i = 0;i < ID_LEN - 1;i++) {
		if (temp[i] < '0' || temp[i] > '9') {
			return 0;
		}
	}
	strcpy(customer->id, temp);
	return 1;
}





void printCustomer(const Customer* customer) {
	printf("Customer Details:\n");
	printf("-----------------\n");
	printf("Name: %s\n", customer->name);
	printf("Id: %s\n", customer->id);

}

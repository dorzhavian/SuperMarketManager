#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "product.h"
#include "functions.h"


void initProduct(Product* product)
{	
	printf("Please enter product name up to 20 chars: \n");         
	do {
		myGets(product -> name, NAME_LEN);
//		if (!product->name);
//			printf("Invalid input! Please try again.");
	} while (!product->name);

	int typeChoice = getProductType();
	strcpy(product -> barCode, preFixTypes[typeChoice]);
	generateAndAddRandomDigits(product->barCode);

	printf("Please enter price: \n");
	do {
		scanf("%f", &product->price);
//		if ((product->price) <= 0)
//			printf("Invalid input for price.\n");
	} while (product->price <= 0);

	printf("Please enter quantity: \n");
	do {
		scanf("%d", &product->quantity);
		//		if ((product->quantity) < 0)
		//			printf("Invalid input for quantity.\n");
	} while (product->quantity < 0);
}




Type getProductType() {

	int temp;
	do {
		printf("Please select a product type: \n");
		for (int i = 0; i < NofTypes; i++) {
			printf("%d for %s\n", i, types[i]);
		}
		printf("Enter your choice: ");
		scanf("%d", &temp);
		if (temp < 0 || temp >= NofTypes) {
			printf("Invalid choice. Please try again.\n");
		}
	} while (temp < 0 || temp >= NofTypes);
	return temp;

}


void printProduct(const Product* product) {
	printf("%21s",product->name);
	printf("%11s", product->barCode);
	printf("%21s", types[product->theType]);     // TO CHECK !!!
	printf("%11.2f", product->price);                 
	printf("%21d17", product->quantity);           // TO CHECK !!!
	printDate(&(product->expierdDate));
}







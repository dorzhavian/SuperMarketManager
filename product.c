#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "product.h"
#include "date.h"
#include "functions.h"


void initProduct(Product* product)
{	
	printf("Please enter product name up to 20 chars: \n");         
	do {
		myGets(product -> name, NAME_LEN);
	} while (!product->name);

	product -> theType = getProductType();
	
	strcpy(product -> barCode, preFixTypes[product->theType]);
	generateAndAddRandomDigits(product->barCode);

	printf("Please enter price: \n");
	do {
		scanf("%f", &product->price);
	} while (product->price <= 0.0);

	printf("Please enter quantity: \n");
	do {
		scanf("%d", &product->quantity);
	} while (product->quantity <= 0);

	int res;
	do {
		res = initDate(&product->expierdDate);
	} while(res == 0);
}




Type getProductType()
{
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
	return (Type)temp;
}

void checkValidBarcodeInput(char* bcInput)
{
	size_t len;
	int isValidPreFix = 0;
	char preFix[3];
	do
	{
		myGets(bcInput, MAX_LEN);                  // CHECK IF NEED FGETS CAUSE REMOVE ENTERS      
		len = strlen(bcInput);
		preFix[0] = bcInput[0];
		preFix[1] = bcInput[1];
		preFix[2] = '\0';
		for (int i = 0; i < NofTypes; i++)
		{
			if (strcmp(preFix, preFixTypes[i]) == 0)
			{
				isValidPreFix = 1;
				break;
			}
		}
		if (!isValidPreFix)
			printf("Invalid type of pre fix!\n");
		if (len != BC_LEN)
			printf("Invalid barcode length\n");
	} while (len != BC_LEN || !isValidPreFix);
}


void printProduct(const Product* product) {
	printf("%-20s %-20s %-20s %-10.2f %-20d ", product->name, product->barCode, types[product->theType], product->price, product->quantity);
	printDate(&(product->expierdDate));
}
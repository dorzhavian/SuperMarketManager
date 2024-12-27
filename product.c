#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Product.h"


int initProduct(Product* product) {

	printf("Please enter product name: \n");
	scanf("%s", product->name);

	printf("Please enter barcode: \n");
	scanf("%s", product->barCode);

	printf("Please enter price: \n");
	if (scanf("%f", &product->price) < 1) {
		printf("Invalid input for price.\n");
		return 0;
	}

	printf("Please enter amount: \n");
	if (scanf("%d", &product->amount) < 1) {
		printf("Invalid input for amount.\n");
		return 0;
	}

	product->theType = getProductType();
	initDate(&product->expierdDate);
	return 1;


}




Type getProductType() {

	int temp;
	do {
		printf("Please select a product type\n");
		for (int i = 0; i < NofTypes; i++) {
			printf("%d - %s\n", i, typeTilte[i]);
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
	printf("Product Details:\n");
	printf("-----------------\n");
	printf("Name: %s\n", product->name);
	printf("Barcode: %s\n", product->barCode);
	printf("Price: %.2f\n", product->price);
	printf("Amount: %d\n", product->amount);
	printf("Type: %s\n", typeTilte[product->theType]);
	printf("Expiration Date:");
	printDate(&(product->expierdDate));
}







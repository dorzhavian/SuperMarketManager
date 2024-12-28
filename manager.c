#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "manager.h"
#include "superMarket.h"
#include "customer.h"
#include "functions.h"

#define MAX_LEN 255


void printMenu()
{
	printf("\n-------------MENU----------------\n");
	printf("0) Show Super Market \n");
	printf("1) Add Product\n");
	printf("2) Add Customer\n");
	printf("3) Customer Shopping\n");
	printf("4) Print Shopping Cart\n");
	printf("5) Customer Shopping Cart Managment\n");
	printf("6) Print Product By Type\n");
	printf("-1) Quit\n");
	printf("---------------------------------\n");
}

int start(SuperMarket* superMarket)
{
	int choice;
	printf("Enter market name: ");
	myGets(superMarket->superMarketName, MAX_LEN);
	do {
		printMenu();
		printf("\nEnter your choice: \n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			printSuperMarket(superMarket);
			break;
		case 1:
			case1(superMarket);
			break;
		case 2:
			case2(superMarket);
			break;
		case 3:
			case3(superMarket);
			break;
		case 4:
			case4(superMarket);
			break;
		case 5:
			case5(superMarket);
			break;
		case 6:
			case6(superMarket);
			break;
		case -1:
			printf("Bye Bye");
			break;
		default:
			printf("Wrong option, please try again!\n");
			break;
		}
	} while (choice != -1);
	return 1;
}

void case1(SuperMarket* superMarket)
{
	char choice;
	char bcInput[BC_LEN];
	printf("Adding new Product? y/Y : ");
	scanf(" %c", &choice);
	if (tolower(choice) == 'y')
	{
		addProductToSuperMarket(superMarket);
		printf("\nProduct Added Successfully!!!\n");
	}
	else
	{
		printf("Please enter a valid barcode of product in the shop.\nBarcode must be 7 length exactly.\nMust have 2 type prefix letters followed by a 5 digits number.\nFor Example: FR20301");
		checkValidBarcodeInput(bcInput);
		int index = isProductExistByBarcode(superMarket, bcInput);
		if (index == -1) 
			printf("No such product barcode in the super market.");
		else 
		{
			printf("How many items you want to add to stock? ");
			int addStock;
			scanf("%d", &addStock);
			superMarket->productsPointersArr[index]->quantity += addStock;
		}
	}
}

void case2(SuperMarket* superMarket)
{
	return;
}

void case3(SuperMarket* superMarket)
{
	return;
}

void case4(SuperMarket* superMarket)
{
	return;
}

void case5(SuperMarket* superMarket)
{
	return;
}

void case6(SuperMarket* superMarket)
{
	return;
}

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "manager.h"

#define MAX_LEN 255

void printMenu()
{
	printf("\n\n-------------MENU----------------\n");
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
	int choice, res;
	do {
	
		printMenu();
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			printSuperMarket(superMarket);
			break;
		case 1:
			res = case1(superMarket);
			if (res == 0)
				printf("\nError in adding product\n");
			break;
		case 2:
			InitAndAddCustomer(superMarket);
			break;
		case 3:
			res = case3(superMarket);
			if (res == 0)
				printf("Error in shopping\n");
			break;
		case 4:
			case4(superMarket);
			break;
		case 5:
			res = case5(superMarket);
			if (res == 0)
				printf("Error in shoppingCart managment\n");
			break;
		case 6:
			printAllProductsByType(superMarket);
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

int case1(SuperMarket* superMarket)
{
	char choice;
	printf("Adding new Product? y/Y : ");
	scanf(" %c", &choice);
	if (tolower(choice) == 'y')
	{
		addProductToSuperMarket(superMarket);
		printf("\nProduct Added Successfully!!!\n");
	}
	else
	{
		if (superMarket->numOfProducts == 0)
			return 0;
		printf("\nDo you want to increase the amout of an existing product? y/Y: ");
		scanf(" %c", &choice);
		if (tolower(choice) == 'y')
		{
			printAllProducts(superMarket);
			updateProductQuantity(superMarket);
		}
		else
			return 1;
	}
	return 1;
}

int case3(SuperMarket* superMarket)
{
	size_t indexCustomer;
	if (possibleToShopping(superMarket) == 0)
		return 0;
	else 
	{
		indexCustomer = indexWhoIsShopping(superMarket);
		if (indexCustomer == -1)
			return 0;
		printAllProducts(superMarket);
		return shopping(superMarket, indexCustomer);
	}
}

int case4(const SuperMarket* superMarket)
{
	size_t res4;
	if (superMarket->numOfCustomers == 0)
	{
		printf("No customer listed to market\n");
		return 0;
	}
	else if (superMarket->numOfProducts == 0)
		printf("No products in market - cannot shop!\n");
	else
	{
		res4 = indexWhoIsShopping(superMarket);
		if (res4 == -1)
			return 0;
		else
			printShoppingCart(&(superMarket->customersArr[res4].cart));
	}
	return 1;
}

int case5(SuperMarket* superMarket)
{ 
	int res5;
	if (superMarket->numOfCustomers == 0)
	{
		printf("No customer listed to market\n");
		return 0;
	}
	else if (superMarket->numOfProducts == 0)
	{
		printf("No products in market - cannot shop!\n");
	}
	else
	{
		size_t customerIndex = indexWhoIsShopping(superMarket);
		if (customerIndex == -1)
			return 0;
		else if (superMarket->customersArr[customerIndex].cart.numOfSInCart == 0)
		{
			printf("\nCustomer cart is empty!\n");
			return 0;
		}
		else 
			res5 = buyAtTheSuperMarket(superMarket, customerIndex);
	}
	return 1;
}


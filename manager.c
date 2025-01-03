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
			case0(superMarket);
			break;
		case 1:
			res = case1(superMarket);
			if (res == 0)
				printf("\nError in adding product\n");
			break;
		case 2:
			case2(superMarket);
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

void case0(SuperMarket* superMarket)
{
	printSuperMarket(superMarket);
}

//move to superMarket ????
int case1(SuperMarket* superMarket)
{
	//make method addOrUpdateProductToSuperMarket
	char choice;
	printf("Adding new Product? y/Y : ");
	scanf(" %c", &choice);
	if (tolower(choice) == 'y')
		addNewProduct(superMarket);
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

void case2(SuperMarket* superMarket)
{
	InitAndAddCustomer(superMarket);
}

int case3(SuperMarket* superMarket)
{
	size_t indexCustomer, indexProduct, res3;
	char choice;
	if (superMarket->numOfCustomers == 0)
	{
		printf("No customer listed to market\n");
		return 0;
	}
	else if(superMarket->numOfProducts == 0)
	{
		printf("No products in market - cannot shop!\n");
		return 0;
	}
	else 
	{
		indexCustomer = indexWhoIsShopping(superMarket);
		if (indexCustomer == -1)
			return 0;
		printAllProducts(superMarket);
		while (1)
		{
			printf("Do you want to shop for a product? y/Y, anything else to exit!");
			scanf(" %c", &choice);
			if (tolower(choice) != 'y')
			{
				printf("---------- Shopping ended ----------\n");
				break;
			}
			indexProduct = productIndexByBarcode(superMarket);
			if (indexProduct != -1)
			{
				res3 = itemIndexInCart(&(superMarket->customersArr[indexCustomer].cart), superMarket->productsPointersArr[indexProduct]->barCode);
				if (res3 != -1)
				{
					updateShoppingItemQuantityInCart(&(superMarket->customersArr[indexCustomer].cart), superMarket->productsPointersArr[indexProduct], res3);
				}
				else
				{
					res3 = addShoppingItemToCart(&(superMarket->customersArr[indexCustomer].cart), superMarket->productsPointersArr[indexProduct]);
					if (!res3)
						return 0;
				}
			}
		}
		return 1;
	}
}

int case4(SuperMarket* superMarket)
{
	int res4;
	if (superMarket->numOfCustomers == 0)
	{
		printf("No customer listed to market\n");
		return 0;
	}
	else if (superMarket->numOfProducts == 0)
		printf("No products in market - cannot shop!\n");
	else
	{
		//printAllCustomers(superMarket);
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
	int res5, customerIndex;    // maybe change index to size_t , also at int indexWhoIsShopping(SuperMarket* superMarket)
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
		customerIndex = indexWhoIsShopping(superMarket);
		if (customerIndex == -1)
			return 0;
		else if (superMarket->customersArr[customerIndex].cart.numOfSInCart == 0)
		{
			printf("\nCustomer cart is empty!\n");
			return 0;
		}
		else 
		{
			res5 = buyAtTheSuperMarket(superMarket, customerIndex);
		}
	}
	return 1;
}

//move to the supermarket???
int indexWhoIsShopping(SuperMarket* superMarket)
{
	char* choice;
	printAllCustomers(superMarket);
	printf("\nWho is shopping? Enter customer ID\n");
	choice = getStrExactLength();			//REMEMBER TO FREE()!!!!!!!!!!!!!!!!!
	if (!choice)
	{
		return -1;
	}
	int res;
	res = isExistID(choice, superMarket);
	if (!res)
	{
		printf("\nThis customer not listed\n");
		free(choice);
		return -1;
	}
	int index = findIndexOfCustomer(superMarket, choice);				//REMEMBER TO FREE()!!!!!!!!!!!!!!!!!
	free(choice);
	return index;
}

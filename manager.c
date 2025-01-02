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
		printf("\nEnter your choice: \n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			case0(superMarket);
			break;
		case 1:
			case1(superMarket);
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

void case0(SuperMarket* superMarket)
{
	printSuperMarket(superMarket);
}

//move to superMarket ????
void case1(SuperMarket* superMarket)
{
	//make method addOrUpdateProductToSuperMarket
	char choice;
	printf("Adding new Product? y/Y : ");
	scanf(" %c", &choice);
	if (tolower(choice) == 'y')
		addNewProduct(superMarket);
	else
		updateProductQuantity(superMarket);
}

void case2(SuperMarket* superMarket)
{
	InitAndAddCustomer(superMarket);
}

int case3(SuperMarket* superMarket)
{
	int res3;
	if (superMarket->numOfCustomers == 0)
	{
		printf("No customer listed to market\n");
		return 0;
	}
	else if(superMarket->numOfProducts == 0)
	{
		printf("No products in market - cannot shop!\n");
		
	}
	else 
	{
		res3 = whoIsShopping(superMarket);
		if (res3 == 0)
			return 0;
	}
	return 1;
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
	{
		printf("No products in market - cannot shop!\n");

	}
	else
	{
		res4 = whoIsShopping(superMarket);
		if (res4 == 0)
			return 0;
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
		res5 = whoIsShopping(superMarket);
		if (res5 == 0)
			return 0;
	}
	return 1;
}

void case6(SuperMarket* superMarket)
{
	return;
}


//move to the supermarket???
int whoIsShopping(SuperMarket* superMarket)
{
	char* choice;
	printAllCustomers(superMarket);
	printf("Doing shopping now!!!\nWho is shopping? Enter customer name or ID\n");
	choice = getStrExactLength();			//REMEMBER TO FREE()!!!!!!!!!!!!!!!!!
	if (!choice)
	{
		return 0;
	}
	int res1, res2;
	res1 = isExistID(choice, superMarket);
	res2 = isExistName(choice, superMarket);
	if (!res1 && !res2)
	{
		printf("This customer not listed");
		return 0;
	}
	return 1;
}

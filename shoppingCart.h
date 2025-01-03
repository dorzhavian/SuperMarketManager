#pragma once

#include "shoppingItem.h"

typedef struct {
	ShoppingItem** shoppingItemsArr;
	int numOfSInCart;
} ShoppingCart;

int initShoppingCart(ShoppingCart* shoppingCart);
void printShoppingCart(const ShoppingCart* shoppingCart);
float calcOfTotalPay(const ShoppingCart* shoppingCart); 
int addShoppingItemToCart(ShoppingCart* shoppingCart, Product* product);
void freeShoppingCart(ShoppingCart* shoppingCart);
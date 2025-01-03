#pragma once

#include "shoppingItem.h"

typedef struct {
	ShoppingItem** shoppingItemsArr;
	int numOfSInCart;
} ShoppingCart;

int initShoppingCart(ShoppingCart* shoppingCart);
void printShoppingCart(const ShoppingCart* shoppingCart);
int calcOfTotalPay(const ShoppingCart* shoppingCart); 
int addShoppingItemToCart(ShoppingCart* shoppingCart, const ShoppingItem* shoppingItem);
void freeShoppingCart(ShoppingCart* shoppingCart);
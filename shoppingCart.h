#pragma once

#include "shoppingItem.h"

typedef struct {
	ShoppingItem** shoppingItemsArr;
	int numOfSInCart;
} ShoppingCart;

int initShoppingCart(ShoppingCart* shoppingCart);
void printShoppingCart(const ShoppingCart* shoppingCart);
int calcOfTotalPay(const ShoppingCart* shoppingCart); 
void addProductToCart(ShoppingCart* shoppingCart, ShoppingItem* shoppingItem);
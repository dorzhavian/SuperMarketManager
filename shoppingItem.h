#pragma once

#include "product.h"

typedef struct {

	char barCode[BC_LEN];
	float price;
	int amount;

	//Product p ???

} ShoppingItem;

int initShoppingItem(ShoppingItem* shoppingItem);                        // convert product to shoppingItem for adding to shoppingCart
void printShoppingItem(const ShoppingItem* shoppingItem);
#pragma once

#include "Product.h"

typedef struct {
	char barCode[BC_LEN];
	float price;
	int amount;

	//Product p ???

} ShoppingItem;

int initShoppingItem(ShoppingItem* shoppingItem);
void printShoppingItem(const ShoppingItem* shoppingItem);
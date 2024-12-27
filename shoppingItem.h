#pragma once

#include "Product.h"

typedef struct {
	char barCode[BC_LEN];
	float price;
	int amount;

	//Product p ???

} ShoppingItem;

int initShoppingItem(ShoppingItem* shoppingItem, Product* product);                        // convert product to shoppingItem for adding to shoppingCart
void printShoppingItem(const ShoppingItem* shoppingItem);
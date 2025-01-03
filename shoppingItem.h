#pragma once

#include <string.h>
#include "product.h"

typedef struct {

	char barCode[BC_LEN];
	float price;
	int quantity;

} ShoppingItem;

void createShoppingItem(Product* product, ShoppingItem* shoppingItem); // convert product to shoppingItem for adding to shoppingCart
int initShoppingItem(Product* p);
void printShoppingItem(const ShoppingItem* shoppingItem);
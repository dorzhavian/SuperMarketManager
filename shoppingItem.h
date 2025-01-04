#pragma once

#include <string.h>
#include "product.h"

typedef struct {

	char barCode[BC_LEN];
	float price;
	int quantity;

} ShoppingItem;

void initShoppingItem(Product* product, ShoppingItem* shoppingItem); 

void printShoppingItem(const ShoppingItem* shoppingItem);
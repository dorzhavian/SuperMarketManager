#define _CRT_SECURE_NO_WARNINGS

#include "shoppingItem.h"

void initShoppingItem(Product* product,ShoppingItem* shoppingItem)
{
    strcpy(shoppingItem->barCode, product->barCode);
    shoppingItem->price = product->price;
    shoppingItem->quantity = 0;
}

void printShoppingItem(const ShoppingItem* shoppingItem)
{
    printf("Item %s count %d price %.2f per item\n", shoppingItem->barCode, shoppingItem->quantity, shoppingItem->price);
}

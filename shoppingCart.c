#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "shoppingCart.h"
#include "shoppingItem.h"

int initShoppingCart(ShoppingCart* shoppingCart)
{
    if (shoppingCart == NULL)
        return 0;
    shoppingCart->shoppingItemsArr = (ShoppingItem**)malloc(sizeof(ShoppingItem*));
    if (shoppingCart->shoppingItemsArr == NULL)
        return 0;                             // REMEMBER TO FREE ()!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    shoppingCart->numOfSInCart = 0;
    return 1;
}

void printShoppingCart(const ShoppingCart* shoppingCart)
{
}

int calcOfTotalPay(const ShoppingCart* shoppingCart)
{
    return 0;
}

void addProductToCart(ShoppingCart* shoppingCart, ShoppingItem* shoppingItem)
{
}

void freeShoppingCart()
{
}


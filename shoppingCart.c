#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "shoppingCart.h"

int initShoppingCart(ShoppingCart* shoppingCart)
{
    if (shoppingCart == NULL)
        return 0;
    shoppingCart->shoppingItemsArr = (ShoppingItem**)malloc(sizeof(ShoppingItem*));
    if (shoppingCart->shoppingItemsArr == NULL)
        return 0;                             // REMEMBER TO FREE ()!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    shoppingCart-> numOfSInCart = 0;
    return 1;
}

void printShoppingCart(const ShoppingCart* shoppingCart)
{
    for (size_t i = 0; i < shoppingCart->numOfSInCart; i++)
    {
        printShoppingItem(shoppingCart->shoppingItemsArr[i]);
    }
}

float calcOfTotalPay(const ShoppingCart* shoppingCart)
{
    float check = 0;
    for (size_t i = 0; i < shoppingCart->numOfSInCart; i++)
    {
        check += (shoppingCart->shoppingItemsArr[i]->price);
    }
    return check;
}

int addShoppingItemToCart(ShoppingCart* shoppingCart, Product* product)
{
    int num;
    ShoppingItem* pS = (ShoppingItem*)malloc(sizeof(ShoppingItem));
    if (!pS)
        return 0;           // REMEMBER TO FREE() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    shoppingCart->shoppingItemsArr = (ShoppingItem**)safeRealloc(shoppingCart->shoppingItemsArr, (shoppingCart->numOfSInCart + 1) * sizeof(ShoppingItem*));
    if (!shoppingCart->shoppingItemsArr)
    {
        free(pS);
        return 0;          // REMEMBER TO FREE() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    do {
        printf("How many items do you want? max %d", product->quantity);
        scanf("%d", &num);
    } while (num < 1 || num > product->quantity);
    createShoppingItem(product, pS);
    pS->quantity = num;
    shoppingCart->shoppingItemsArr[shoppingCart->numOfSInCart] = pS;
    shoppingCart-> numOfSInCart += num;
    product->quantity -= num;
    return 1;
}

void freeShoppingCart(ShoppingCart* shoppingCart)
{
    for (size_t i = 0; i < shoppingCart->numOfSInCart; i++)
    {
        free(shoppingCart->shoppingItemsArr[i]);
    }
    free(shoppingCart);
}


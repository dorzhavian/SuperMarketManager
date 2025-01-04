#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "shoppingCart.h"

int initShoppingCart(ShoppingCart* shoppingCart)
{
    shoppingCart->shoppingItemsArr = (ShoppingItem**)malloc(sizeof(ShoppingItem*));
    if (!shoppingCart->shoppingItemsArr)
        return 0;                           
    shoppingCart-> numOfSInCart = 0;
    return 1;
}

void printShoppingCart(ShoppingCart* shoppingCart)
{
    if (shoppingCart->numOfSInCart == 0)
        printf("Cart is empty\n");
    else 
    {
        float check = calcOfTotalPay(shoppingCart);
        for (size_t i = 0; i < shoppingCart->numOfSInCart; i++)
        {
            printShoppingItem(shoppingCart->shoppingItemsArr[i]);
        }
        printf("Total bill to pay: %.2f\n\n", check);
    }
}

float calcOfTotalPay(const ShoppingCart* shoppingCart)
{
    float check = 0;
    for (size_t i = 0; i < shoppingCart->numOfSInCart; i++)
    {
        check += ((shoppingCart->shoppingItemsArr[i]->price) * (shoppingCart->shoppingItemsArr[i]->quantity));
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
        printf("How many items do you want? max %d\n", product->quantity);
        scanf("%d", &num);
    } while (num < 1 || num > product->quantity);
    createShoppingItem(product, pS);
    pS->quantity = num;
    shoppingCart->shoppingItemsArr[shoppingCart->numOfSInCart] = pS;
    shoppingCart-> numOfSInCart++;
    product->quantity -= num;
    return 1;
}

void updateShoppingItemQuantityInCart(ShoppingCart* shoppingCart, Product* product, size_t index)
{
    int num;
    do {
        printf("How many items do you want? max %d", product->quantity);
        scanf("%d", &num);
    } while (num < 1 || num > product->quantity);
    shoppingCart->shoppingItemsArr[index]->quantity += num;
    product->quantity -= num;
}

size_t itemIndexInCart(const ShoppingCart* shoppingCart,const char* barcode)
{
    for (size_t i = 0; i < shoppingCart->numOfSInCart; i++)
    {
        if (strcmp(shoppingCart->shoppingItemsArr[i]->barCode , barcode) == 0)
            return i;
    }
    return -1;
}

void freeShoppingCart(ShoppingCart* shoppingCart)
{
    if (!shoppingCart || !shoppingCart->shoppingItemsArr)
        return;
    for (size_t i = 0; i < shoppingCart->numOfSInCart; i++)
    {
        free(shoppingCart->shoppingItemsArr[i]);
    }
    free(shoppingCart->shoppingItemsArr);
    
}
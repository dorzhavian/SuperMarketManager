#pragma once

#include "Date.h"

#define NAME_LEN 21
#define BC_LEN 8

typedef enum { eShelf, eFrozen, eFridge, eFruitVegtable, NofTypes } Type;
static const char* typeTilte[NofTypes] = { "SH-Shlef", "FZ-Frozen", "FR-Fridge","FV-FruitVegtable" };



typedef struct {
	char name[NAME_LEN];
	char barCode[BC_LEN];
	float price;
	int amount;
	Date expierdDate;
	Type theType;

}Product;


int initProduct(Product* product);

void printProduct(Product* product);

Type getProductType();

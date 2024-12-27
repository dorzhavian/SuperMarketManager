#pragma once

#include "Date.h"

#define NAME_LEN 21
#define BC_LEN 8

typedef enum { eShelf, eFrozen, eFridge, eFruitVegtable, NofTypes } Type;
static const char* types[NofTypes] = { "Fruit Vegtable", "Fridge","Frozen" , "Shelf"};
static const char* preFixTypes[NofTypes] = { "FV", "FR","FZ", "SH"};



typedef struct {
	char name[NAME_LEN];
	char barCode[BC_LEN];
	float price;
	int quantity;
	Date expierdDate;
	Type theType;

}Product;


void initProduct(Product* product);

void printProduct(const Product* product);

Type getProductType();

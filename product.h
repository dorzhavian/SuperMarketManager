#pragma once

#include "date.h"
#include "functions.h"

#define NAME_LEN 21
#define BC_LEN 8
#define MAX_LEN 255

typedef enum { eFruitVegtable, eFridge, eFrozen, eShelf, NofTypes } Type;
static const char* types[NofTypes] = {"Fruit Vegtable", "Fridge", "Frozen" , "Shelf"};
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

void checkValidBarcodeInput(char* bcInput);

Type getProductType();

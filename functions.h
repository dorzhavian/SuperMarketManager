#pragma once

#include <stdio.h>

//#include "superMarket.h"		??
#define MAX_LEN 255	

void* safeRealloc(void* base, size_t newByteCount);   // safe realloc

char* myGets(char* buffer, int size);

char* getStrExactLength();

void fixNameStr(char* nameStr);

int isNumericString(const char* str);

void generateAndAddRandomDigits(char* buffer);

//int uniqueBarcode(char* buffer, const SuperMarket* superMarket);			//added


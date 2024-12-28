#pragma once

#include <stdio.h>

void* safeRealloc(void* base, size_t newByteCount);   // safe realloc

char* myGets(char* buffer, int size);

void fixNameStr(char* nameStr);

int isNumericString(const char* str);

void generateAndAddRandomDigits(char* buffer);

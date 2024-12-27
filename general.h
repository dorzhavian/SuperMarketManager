#pragma once

void* safeRealloc(void* base, size_t newByteCount);   // safe realloc

char* myGets(char* buffer, int size);

char* getStrExactLength();

void fixNameStr(char* nameStr);

int isNumericString(const char* str);
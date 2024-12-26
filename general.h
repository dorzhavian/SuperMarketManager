#pragma once

char* myGets(char* buffer, int size);    //function for safe and better fgets

void* safeRealloc(void* base, size_t newByteCount);   // safe realloc
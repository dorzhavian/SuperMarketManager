#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functions.h"

#define MAX_LEN 255

char* myGets(char* buffer, int size)
{
	char* ok;
	if (buffer != NULL && size > 0)
	{
		do {
			ok = fgets(buffer, size, stdin);
		} while (ok && ((strlen(buffer) <= 1) && (iscntrl(buffer[0]))));
		if (ok)
		{
			char* back = buffer + strlen(buffer);
			//trim end spaces
			while ((buffer < back) && (iscntrl(*--back)));
			*(back + 1) = '\0';
			return buffer;
		}
		buffer[0] = '\0';
	}
	return NULL;
}

void generateAndAddRandomDigits(char* buffer) 
{
	for (size_t i = 2; i < 7; i++) {
		buffer[i] = '0' + (rand() % 10); 
	}
	buffer[7] = '\0'; 
}

void* safeRealloc(void* base, size_t newByteCount)
{
	void* temp = realloc(base, newByteCount);
	if (!temp)
		free(base);
	return temp;
}

void fixNameStr(char* nameStr)
{
	nameStr[0] = toupper(nameStr[0]); 
	for (int i = 1; nameStr[i] != '\0'; i++) {
		nameStr[i] = tolower(nameStr[i]); 
	}
}

int isNumericString(const char* str) {
	if (*str == '\0') {
		return 0;
	}
	while (*str) {
		if (!isdigit((unsigned char)*str)) {
			return 0; 
		}
		str++;
	}
	return 1; 
}
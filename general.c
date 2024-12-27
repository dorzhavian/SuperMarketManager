#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "general.h"

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

char* getStrExactLength()
{
	char* theStr = NULL;
	int len;
	char inpStr[MAX_LEN];
	// print to user from the func use this func
	myGets(inpStr, sizeof(inpStr));
	theStr = strdup(inpStr);
	return theStr;
}

void* safeRealloc(void* base, size_t newByteCount)
{
	void* temp = realloc(base, newByteCount);
	if (!temp)
		free(base);
	return temp;
}

void customerUserName(char* firstName, char* lastName)
{
	printf("Please enter first name: (up to 20 letters)");
}

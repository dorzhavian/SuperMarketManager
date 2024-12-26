#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "general.h"

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

void* safeRealloc(void* base, size_t newByteCount)
{
	void* temp = realloc(base, newByteCount);
	if (!temp)
		free(base);
	return temp;
}

void customerUserName(char* firstName, char* lastName)
{
	//??
}

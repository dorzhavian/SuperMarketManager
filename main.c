#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "superMarket.h"
#include "manager.h"
#include "customer.h"


int main() 
{
	SuperMarket s;
	int res = initSuperMarket(&s);
	if (!res)
	{
		free(&s);
		printf("MEMORY FAILED");
	}
	start(&s);
	freeSuperMarket(&s);
	return 1;
}
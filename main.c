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
	initSuperMarket(&s);
	if (!initSuperMarket(&s))
	{
		free(&s);
		printf("MEMORY FAILED");
	}
	start(&s);
	free(s.productsPointersArr);
	free(s.customersArr);
	return 1;
}
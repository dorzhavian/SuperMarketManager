#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "customer.h"


int main() {
	Customer c1;
	if (!initCustomer(&c1))
		printf("ERROR");
	else
	{
		printCustomer(&c1);
	}
	free(c1.name);
	return 1;
}
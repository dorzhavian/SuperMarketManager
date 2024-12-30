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
	free(s.productsPointersArr);
	
	for (int i = 0; i < s.numOfCustomers; i++)
	{
		if (s.customersArr[i].name != NULL)
		{
			free(s.customersArr[i].name);			// שחרר את הזיכרון שהוקצה לשם
			s.customersArr[i].name = NULL;			// טוב להשאיר את המצביע ריק כדי למנוע בעיות
		}
		//free(s.customersArr[i].name);				//ASK EFRAT
	}
	free(s.customersArr);
	free(s.superMarketName);
	return 1;
}
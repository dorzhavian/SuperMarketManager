#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "date.h"

#define DATE_LEN 9

int initDate(Date* date) {
	char temp[DATE_LEN] = { 0 };
	printf("Enter a date in the format ddmmyyyy: ");
	scanf("%s", temp);

	if (strlen(temp) != 8) {
		printf("Invalid date format. Must be 8 digits.\n");
		return 0;
	}

	//divide the string
	char dayPart[3] = { temp[0],temp[1],'\0' }; //dd
	char monthPart[3] = { temp[2],temp[3],'\0' }; //mm
	char yearPart[5] = { temp[4],temp[5],temp[6],temp[7],'\0' }; //yyyy
	
	//convert to int
	int day = atoi(dayPart);
	int month = atoi(monthPart);
	int year = atoi(yearPart);

	if (month < 1 || month > 12) 
		return 0; 

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) 
	{
		if (day < 1 || day > 31) 
			return 0;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) 
	{
		if (day < 1 || day > 30) 
			return 0;
	}
	if (month == 2) 
	{
		if (day < 1 || day > 28) 
			return 0;
	}
	if (year < 2024 || year > 2030)
		return 0;

	date->day = day;
	date->month = month;
	date->year = year;
	return 1;
}


void printDate(const Date* date) {
	printf("%d/%d/%d\n", date->day, date->month, date->year);
}


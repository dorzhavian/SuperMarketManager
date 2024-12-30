#pragma once
#include "functions.h"


typedef struct {
	int day;
	int month;
	int year;
}Date;



int initDate(Date* date);
void printDate(const Date* date);
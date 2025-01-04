#pragma once
#include "functions.h"


typedef struct {
	int day;
	int month;
	int year;
}Date;


int initDate(Date* date);

int checkValidDate(int year, int month, int day);

void printDate(const Date* date);
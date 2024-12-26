#pragma once

typedef struct {
	int day;
	int month;
	int year;
}Date;



int initDate(Date* date);
void printDate(const Date* date);
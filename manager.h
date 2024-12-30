#pragma once

#include "superMarket.h"
#include "customer.h"
#include "functions.h"

void printMenu();

int start(SuperMarket* superMarket);

void case0(SuperMarket* superMarket);

void case1(SuperMarket* superMarket);

void case2(SuperMarket* superMarket);

void case3(SuperMarket* superMarket);

void case4(SuperMarket* superMarket);

void case5(SuperMarket* superMarket);

void case6(SuperMarket* superMarket);

int isExistName(const Customer* customer, const SuperMarket* superMarket);

int isExistID(const Customer* customer, const SuperMarket* superMarket);



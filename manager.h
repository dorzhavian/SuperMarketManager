#pragma once

#include "superMarket.h"
#include "customer.h"
#include "functions.h"

void printMenu();

int start(SuperMarket* superMarket);

void case0(SuperMarket* superMarket);

void case1(SuperMarket* superMarket);

void case2(SuperMarket* superMarket);

int case3(SuperMarket* superMarket);

int case4(SuperMarket* superMarket);

int case5(SuperMarket* superMarket);

void case6(SuperMarket* superMarket);

int isExistName(const char* customer, const SuperMarket* superMarket);

int isExistID(const char* customer, const SuperMarket* superMarket);

int whoIsShopping(SuperMarket* superMarket);



/*
STRAIGHT LINE DEPRECIATION CALCULATOR
Written by: Haifaa Abushaaban
Date: 2021/04/14-21
Formula:
	1 / useful life in years = depreciation rate
	cost - residual value = depreciable amount
	depreciable amount * depreciation rate (* (month / 12) when partial year) = depreciation expense
Instructions:
1. input the appropriate values
2. compile the program:
    a) gcc -Wall -std=c99 straightLine.c
    b) ./a.out
*/

#include <stdio.h>

#define USELIFE 5 // estimated useful life in years must be inputted

int main(){

	// constants

	// input values below
	double cost = 33000.00; // cost of PPE
	double resVal = 3000.00; // residual value
	double month = 0.00; // current month is 12 - months left of the year
	// end of input values

	int useLifeCount = 0;
	double depAmt = cost - resVal; // depreciable amount
	double depRate = 1.00 / USELIFE; // straight line depreciation rate

	// changing
	double depExp = 0.00; // starting is 0
	double carryAmt = cost - depExp;
	double accDep = 0.00;

	// calender
	double year = (12.00 - month) / 12.00;
	int yearly = 2021;

	printf("       Year  Depreciation rate        Depreciation Expense        Accumilated Depreciation        Carrying Amount\n");

	printf("%2d/12, %d%19.2f%28.2f%32.2f%23.2f\n", (int)(year * 12), yearly, depRate, depExp, accDep, carryAmt);

	while (useLifeCount <= USELIFE){

    if (year == 0) break;
    
		depExp = year * depRate * depAmt; // year end * depreciation rate * depreciable amount
		carryAmt = carryAmt - depExp; // carrying amount
		accDep += depExp; // accumilated depreciation (sum)

		printf("%2d/12, %d%19.2f%28.2f%32.2f%23.2f\n", (int)(year * 12), yearly, depRate, depExp, accDep, carryAmt);

		++useLifeCount;
		year = 1;

		if (useLifeCount == USELIFE){ // when item not purchased Jan 1st, must account for months
			year = month / 12.00;
		}

		++yearly;

	}

	return 0;

}
/*
DIMINISHING DEPRECIATION CALCULATOR
Written by: Haifaa Abushaaban
Date: 2021/04/14-21
Formula:
	1 / useful life in years = depreciation rate
	depreciation rate * multiplier = depreciation rate
	carrying amount at the beginning of the year * depreciation rate (* (month / 12) when partial year) = depreciation expense
Instructions:
1. input the appropriate values
2. compile the program:
    a) gcc -Wall -std=c99 diminishing.c
    b) ./a.out
*/

#include <stdio.h>

#define USELIFE 5 // estimated useful life in years must be inputted

int main(){

	// constant

	// input values below
	double cost = 33000;
	/* purchase price and all costs that are necessary to get the
     PPE ready for its intended use excluding the residual
     value (final carrying amount should approximate the residual value)
	*/
	double resVal = 3000.00;
	double multiplier = 2.00; // 2 for double
	double month = 0.00;
	// starting month (NOT ending) (ie, April 1st = 12 - 9 months left = 3 or April 31st = 12 - 8 months left = 4)
	// end of input values

	double depRate = (1.00 / USELIFE) * multiplier;
	// depreciation rate = 100% / useful life in years

	// changing per year
	double depExp = 0.00; // yearly depreciation expense (0 when first purchased)
	double carryAmt = cost - depExp; // carrying amount at the beginning of each year
	double accDep = 0.00; // accumilated depreciation
	int useLifeCount = 0;

	// calender
	double year = (12.00 - month) / 12.00;
	int yearly = 2021; // start year

	printf("       Year  Depreciation rate        Depreciation Expense        Accumilated Depreciation        Carrying Amount\n");

	printf("%2d/12, %d%19.2f%28.2f%32.2f%23.2f\n", (int)(year * 12), yearly, depRate, depExp, accDep, carryAmt); // initial amounts

	while (useLifeCount <= USELIFE){

		if (year == 0) break;

		depExp = year * depRate * carryAmt;
		carryAmt = carryAmt - depExp;

		if (carryAmt < resVal){ // must be adjusted to the residual value
			carryAmt = carryAmt + depExp; // re calculate the carrying amount
			depExp = carryAmt - resVal;
			carryAmt = resVal;
		}

		accDep += depExp;

		printf("%2d/12, %d%19.2f%28.2f%32.2f%23.2f\n", (int)(year * 12), yearly, depRate, depExp, accDep, carryAmt);

		++useLifeCount;
		year = 1;

		if (useLifeCount == USELIFE){
			year = month / 12.00; // 12 months of the year
		}

		++yearly;

	}

	return 0;
}
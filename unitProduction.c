/*
UNITS OF PRODUCTION DEPRECIATION CALCULATOR
Written by: Haifaa Abushaaban
Date: 2021/04/14-21
Formula:
	cost - residual value = depreciable amount
	depreciable amount / estimated total units of activity = depreciation rate / unit
	depreciation rate / unit * units of activity during each year = depreciation expense
Instructions:
1. input the appropriate values
2. compile the program:
    a) gcc -Wall -std=c99 unitProduction.c
    b) ./a.out
*/

#include <stdio.h>

#define USELIFE 5 // estimated useful life in years must be inputted

int main(){

	// constants
	// input values below
	double cost = 33000.00; // total cost of PPE
	double resVal = 3000.00; // residual value
	double estUnitAct = 100000; // estimated total units of activity
	int yearUnitAct[USELIFE] = {15000, 30000, 20000, 25000, 10000};
	// yearly unit of activity starting from year 1, 2, ... USELIFE number of years
	// end of input values

	int useLifeCount = 0;
	double depAmt = cost - resVal;
	double depRateUnit = depAmt / estUnitAct; // if there is a different fixed rate, should be inputted here

	// changing
	double depExp = 0.00;
	double carryAmt = cost - depExp;
	double accDep = 0.00;

	// calender
	int year = 0;
	int yearly = 2021;

	printf("Year        Units of Production        Depreciation Rate / Unit        Depreciation Expense        Accumilated Depreciation        Carrying Amount\n");

	printf("%4.2d%27d%32.2f%28.2f%32.2f%23.2f\n", yearly, yearUnitAct[year], depRateUnit, depExp, accDep, carryAmt);

	while (useLifeCount < USELIFE){

		depExp = depRateUnit * yearUnitAct[year]; // depreciation rate/unit * units of activity during the year
		carryAmt = carryAmt - depExp;
		accDep += depExp;

		printf("%4.2d%27d%32.2f%28.2f%32.2f%23.2f\n", yearly, yearUnitAct[year], depRateUnit, depExp, accDep, carryAmt);

		++useLifeCount;
		++year;
		++yearly;
	}

	return 0;

}
/*
INSTALLMENT PAYMENT SCHEDULE CALCULATOR
Written by: Haifaa Abushaaban
Date: 2021/04/14-21
Formula:
	interest expense = principal balance * interest rate * period (normally monthly)
	periodic reduction of the principal balance = periodic cash payment - interest expense
	principal balance = principal balance - periodic reduction
Instructions:
1. input the appropriate values
2. compile the program:
    a) gcc -Wall -std=c99 -lm payableSchedule.c
    b) ./a.out
*/

#include <stdio.h>
#include <math.h>

int main (void){

	// constants
	// input values below
	double principalBal = 120000.00; // principal to be paid
	float month = 0.0833333; // monthly (1/12 = 0.0833333)
	double rate = 0.04; // interest %
	double cashPay = 2210.00; // periodic payment installments
	// end of input values

	int interestPeriod = 0;
	double interestExp = 0.00;
	double reduction = 0.00;

	printf("Interest period        Cash Payment        Interest Expense        Reduction of Principal        Principal Balance\n");

	printf("%15d%20.2f%24.2f%30.2f%25.2f\n", interestPeriod, cashPay, interestExp, reduction, principalBal);

	while (principalBal >= 0){

		++interestPeriod; // the month has increased

		interestExp = principalBal * rate * month; // interest expense this (1) month calculated using the rate

		reduction = cashPay - interestExp; // reduction for principal

		principalBal = principalBal - reduction; // current principal balance

		printf("%15d%20.2f%24.2f%30.2f%25.2f\n", interestPeriod, cashPay, interestExp, reduction, principalBal);
    
	}

	printf("Total years to pay payable: %f\n", ceil(interestPeriod * month));
	// the ceiling function rounds the number up

	return 0;
}
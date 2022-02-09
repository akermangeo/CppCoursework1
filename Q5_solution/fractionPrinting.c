#include <stdio.h>

#include "fractionPrinting.h"

int static print_fraction(int numerator1, int numerator2, int denominator1, int denominator2);

void print_fractions(const int* fractions)
{
	int array_length = fractions[0];
	for (int index = 1; index < array_length * 4 + 1; index += 4)
	{
		int numerator1 = fractions[index];
		int numerator2 = fractions[index + 1];
		int denominator1 = fractions[index + 2];
		int denominator2 = fractions[index + 3];
		print_fraction(numerator1, numerator2, denominator1, denominator2);
	}
}

int static print_fraction(int numerator1, int numerator2, int denominator1, int denominator2)
{
	printf("%d, %d, %d, %d", numerator1, numerator2, denominator1, denominator2);
}

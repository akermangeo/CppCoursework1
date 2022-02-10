#include <stdio.h>

#include "fractionPrinting.h"

void static print_fraction(int numerator1, int numerator2, int denominator1, int denominator2);

void print_fractions(const int* fractions, int fractions_length)
{
	for (int index = 0; index < fractions_length * 4; index += 4)
	{
		int numerator1 = fractions[index];
		int numerator2 = fractions[index + 1];
		int denominator1 = fractions[index + 2];
		int denominator2 = fractions[index + 3];
		print_fraction(numerator1, numerator2, denominator1, denominator2);
	}
}

void static print_fraction(int numerator1, int numerator2, int denominator1, int denominator2)
{
	printf("%d, %d, %d, %d", numerator1, numerator2, denominator1, denominator2);
}

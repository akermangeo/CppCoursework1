#include <stdio.h>

#include "fractionPrinting.h"

/// <summary>
/// Prints an individual fraction.
/// </summary>
/// <param name="numerator">The numerator.</param>
/// <param name="denominator">The denominator.</param>
void static print_fraction(int numerator, int denominator);

void print_fractions(const int* p_fractions, int fractions_length)
{
	for (int index = 0; index < fractions_length * 2; index += 2)
	{
		int numerator = p_fractions[index];
		int denominator = p_fractions[index + 1];
		print_fraction(numerator, denominator);
	}
	printf("Total working sleepy results: %i", fractions_length);
}

void static print_fraction(int numerator, int denominator)
{
	printf("%d / %d \n", numerator, denominator);
}

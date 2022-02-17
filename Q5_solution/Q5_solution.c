/**When his teacher asked Sleepy to simplify the fraction 26 / 65, he simply cancelled the digit 6
bothfrom the numerator and denominator.To the teacher’s amazement, Sleepy’s cancellation technique
produced the correct result. Write a program to determine all the fractions with two - 
digit numerators and denominators forwhich Sleepy’s technique gives the right answer.  (Split your
program into functions and dividethem between files in an ordered way.)**/

#include <stdlib.h>

#include "fractionFinding.h"
#include "fractionPrinting.h"

int main(void)
{
	int fractions_length;
	const int* p_fractions = find_fractions(&fractions_length);
	print_fractions(p_fractions, fractions_length);
	return EXIT_SUCCESS;
}
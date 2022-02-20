/*
	Write a program that reads numbers until a negative number is read and prints out the number of
	values read, the largest value, the smallest value, and the range.

	We have interpreted the problem as the negative number is not read and therefore not included
	in the minimum and maximum value read and the range outputs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/// <summary>
/// Reads a float from the user.
/// </summary>
/// <returns>The float read.</returns>
float read_float();

int main(void)
{
	float min_num = FLT_MAX;
	float max_num = FLT_MIN;
	int count = 0;
	float num = 0;
	do
	{
		printf("Input value %d: ", count + 1);
		num = read_float();

		if (num >= 0.)
		{
			if (num < min_num)
			{
				min_num = num;
			}
			if (num > max_num)
			{
				max_num = num;
			}
			count++;
		}

	} while (num >= 0.);

	if (count == 0)
	{
		printf("No positive values read");
	}
	else
	{
		float range = max_num - min_num;
		printf("Number of values read = %d\n Largest value read = %f\n Smallest value read = %f\n Range of read values = %f\n", count, max_num, min_num, range);
	}
	return EXIT_SUCCESS;
}

float read_float()
{
	float num;
	int input_counter = scanf_s(" %f", &num);
	if (input_counter < 1)
	{
		printf("Invalid input, exiting...");
		exit(1);
	}
	return num;
}
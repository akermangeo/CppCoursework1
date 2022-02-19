#include <stdio.h>
#include <stdlib.h>

int read_int()
{
	int input = 0;
	int valid_results = scanf_s(" %d", &input);
	if (valid_results < 1)
	{
		printf("Invalid input, exiting...");
		exit(0);
	}
	return input;
}

float read_float()
{
	float input = 0;
	int valid_results = scanf_s("%f", &input);
	if (valid_results < 1)
	{
		printf("Invalid input, exiting...");
		exit(0);
	}
	return input;
}
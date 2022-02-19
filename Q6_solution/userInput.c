#include <stdio.h>
#include <stdlib.h>

#include "userInput.h"

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
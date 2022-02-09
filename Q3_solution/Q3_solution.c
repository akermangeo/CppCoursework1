/* 
	Write a program that reads numbers until a negative number is read and prints out the number of
	values read, the largest value, the smallest value, and the range.

	We have interpreted the problem as the negative number is not read and therefore not included 
	in the minimum and maximum value read and the range outputs.
*/






#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float num = 1., min_num, max_num, range;
	int count = 1;

	printf("Input value %d: ", count);
	scanf("%f", &num);

	max_num = num;
	min_num = num;

	while (num >= 0.)
	{
		if (num < min_num)
		{
			min_num = num;
		}
		else if (num > max_num)
		{
			max_num = num;
		}
		printf("%d %f %f %f\n", count, num, max_num, min_num);
		printf("Input value %d: ", count);
		scanf("%f", &num);
		count++;
	}

	if (count == 1)
	{
		printf("No positive values read");
	}
	else
	{
		range = max_num - min_num;
		printf("Number of values read = %d\n Largest value read = %f\n Smallest value read = %f\n Range of read values = %f\n", count - 1, max_num, min_num, range);
	}
	
	return EXIT_SUCCESS;
}
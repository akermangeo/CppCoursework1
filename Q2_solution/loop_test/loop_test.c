#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, count = 0;
	for (i = 10; i <= 10; i++)
	{
		count++;
	}
	printf("%d\n", count);
	count = 0;
	for (i = 10; i < 10; i++)
	{
		count++;
	}
	printf("%d\n", count);
	count = 0;
	for (i = 10; i >= 1; i -= 4)
	{
		count++;
	}
	printf("%d\n", count);
	count = 0;
	for (i = 10; i == 1; i -= 4)
	{
		count++;
	}
	printf("%d\n", count);
	return EXIT_SUCCESS;
}


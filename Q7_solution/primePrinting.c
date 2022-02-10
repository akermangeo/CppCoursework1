#include <stdio.h>
#include "primePrinting.h"

void print_primes(const int* p_primes, int primes_length)
{
	for (int index = 0; index < primes_length; index++)
	{
		printf("%d \n", p_primes[index]);
	}
}

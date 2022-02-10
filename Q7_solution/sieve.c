#include <stdlib.h>

#include "sieve.h"
#include "math.h"
#include <stdbool.h>

struct sieve_item
{
	int prime_candidate;
	bool is_checked;
};

int* aristhothenes_sieve(int N, int* primes_length)
{
	//check trivial case
	if (N < 2)
	{
		primes_length = NULL;
		return;
	}

	//Initialise the seive.
	struct sieve_item* prime_candidates = (struct sieve_item*)malloc((N - 1) * sizeof(struct sieve_item));
	for (int index = 0; index < (N - 1); index++)
	{
		prime_candidates[index].prime_candidate = index + 2;
		prime_candidates[index].is_checked = false;
	}

	//the highest possible divisor to check
	double number_to_check_limit = sqrt(N);

	int candidate_tracker = 0;
	while (candidate_tracker < number_to_check_limit)
	{
		int next_prime = prime_candidates[candidate_tracker].prime_candidate;
		int next_candidate_to_mark = candidate_tracker + next_prime;
		while (next_candidate_to_mark < N)
		{

		}
	}

}

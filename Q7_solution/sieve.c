#include <stdlib.h>

#include "sieve.h"
#include "math.h"
#include <stdbool.h>

struct sieve_item
{
	int prime_candidate;
	bool is_checked;
};

int* aristhothenes_sieve(size_t N, int* primes_length)
{
	//Check trivial case.
	if (N < 2)
	{
		return NULL;
	}

	//Initialise the seive.
	struct sieve_item* const prime_candidates = (struct sieve_item*)malloc((N - 1) * sizeof(struct sieve_item));
	for (int index = 0; index < (N - 1); index++)
	{
		prime_candidates[index].prime_candidate = index + 2;
		prime_candidates[index].is_checked = false;
	}
	
	//Last element in the sieve.
	const struct sieve_item* const last_candidate = &prime_candidates[N - 2];

	//The highest possible divisor to check.
	double number_to_check_limit = sqrt((double)N);

	//Tracks which candidate we are currently excluding multiples of.
	const struct sieve_item* candidate_tracker = prime_candidates;

	//Count the primes.
	int prime_counter = 0;

	//Loop through unchecked candidates.
	while (candidate_tracker->prime_candidate <= number_to_check_limit)
	{

		//When you find one that is unchecked it must be prime.
		prime_counter++;

		//Mark all the multiples.
		struct sieve_item* next_candidate_to_mark = candidate_tracker + candidate_tracker->prime_candidate;
		while (next_candidate_to_mark <= last_candidate)
		{
			next_candidate_to_mark->is_checked = true;
			next_candidate_to_mark += candidate_tracker->prime_candidate;
		}

		//Advance to the next unmarked candidate.
		do
		{
			candidate_tracker++;
		} while (candidate_tracker->prime_candidate <= number_to_check_limit && candidate_tracker->is_checked == true);
	}

	//Count remaining primes.
	while (candidate_tracker <= last_candidate)
	{
		if (candidate_tracker->is_checked == false)
		{
			prime_counter++;
		}
		candidate_tracker++;
	}

	const struct sieve_item* prime_candidates_copy = prime_candidates;

	//Transfer the primes to the array for return.
	int* primes = (int*)malloc(prime_counter + sizeof(int));
	int coppied_prime_counter = 0;
	while (coppied_prime_counter < prime_counter)
	{
		if (prime_candidates_copy->is_checked == false)
		{
			primes[coppied_prime_counter] = prime_candidates_copy->prime_candidate;
			coppied_prime_counter++;
		}
		prime_candidates_copy++;
	}

	*primes_length = prime_counter;

	free(prime_candidates);
	return primes;
}

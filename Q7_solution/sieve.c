#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "sieve.h"
#include "math.h"


struct sieve_item
{
	int prime_candidate;
	bool is_checked;
};

/// <summary>
/// Finds prime numbers using the sieve of aristhosthenes. Marks all the non-p_primes in the sieve.
/// </summary>
/// <param name="p_sieve_first_element">A pointer to the first element of the sieve.</param>
/// <param name="sieve_length">The length of the sieve.</param>
/// <returns>The number of p_primes found.</returns>
int sieve_for_primes(const struct sieve_item* p_sieve, int sieve_length);

/// <summary>
/// Copies all unchecked p_primes from the sieve to the array.
/// </summary>
/// <param name="p_sieve">The sieve to copy p_primes from.</param>
/// <param name="sieve_prime_count">The number of p_primes in the sieve.</param>
/// <param name="p_primes">The array to hold the p_primes.</param>
void copy_primes(const struct sieve_item* p_sieve, int prime_count, int* p_primes);

int* aristhothenes_sieve(int max_prime, int* p_primes_length)
{
	//Check trivial case.
	if (max_prime < 2)
	{
		return NULL;
	}

	//Initialise the seive.
	struct sieve_item* const p_prime_candidates = (struct sieve_item*)malloc(((size_t)max_prime - 1) * sizeof(struct sieve_item));
	if (p_prime_candidates == NULL)
	{
		printf("Memory allocation failure. (aristhothenes_sieve)\n");
		exit(1);
	}
	for (int index = 0; index < (max_prime - 1); index++)
	{
		p_prime_candidates[index].prime_candidate = index + 2;
		p_prime_candidates[index].is_checked = false;
	}
	
	//Run the sieving process to mark the non-p_primes.
	int prime_count = sieve_for_primes(p_prime_candidates, max_prime-1);

	//Transfer the p_primes to the array for return.
	int* p_primes = (int*)malloc(prime_count * sizeof(int));
	if (p_primes == NULL)
	{
		printf("Memory allocation failure. (aristhothenes_sieve)\n");
		exit(1);
	}
	
	copy_primes(p_prime_candidates, prime_count, p_primes);

	*p_primes_length = prime_count;



	free(p_prime_candidates);
	return p_primes;
}

int* aristhothenes_sieve_advanced(int max_prime, int* p_primes_length)
{
	//Check trivial cases.
	if (max_prime < 2)
	{
		return NULL;
	}

	if (max_prime == 2)
	{
		*p_primes_length = 1;
		int* primes = (int*)malloc(sizeof(int));
		*primes = 2;
		return primes;
	}

	//Initialise the seive with just odd numbers. The prime 2 will be re-included later.
	int sieve_length = (max_prime - 1) / 2;
	struct sieve_item* const p_prime_candidates = (struct sieve_item*)malloc(sieve_length * sizeof(struct sieve_item));
	if (p_prime_candidates == NULL)
	{
		printf("Memory allocation failure. (aristhothenes_sieve_advanced)\n");
		exit(1);
	}
	for (int index = 0; index < sieve_length; index++)
	{
		p_prime_candidates[index].prime_candidate = index * 2 + 3;
		p_prime_candidates[index].is_checked = false;
	}

	//Run the sieving process to mark the non-p_primes.
	int sieve_prime_count = sieve_for_primes(p_prime_candidates, sieve_length);

	//Transfer the p_primes to the array for return. Make space for 2 aswell.
	int total_prime_count = sieve_prime_count + 1;
	int* p_primes = (int*)malloc(total_prime_count * sizeof(int));
	if (p_primes == NULL)
	{
		printf("Memory allocation failure. (aristhothenes_sieve_advanced)\n");
		exit(1);
	}
	*p_primes = 2;

	copy_primes(p_prime_candidates, sieve_prime_count, p_primes+1);

	*p_primes_length = total_prime_count;



	free(p_prime_candidates);
	return p_primes;
}

int sieve_for_primes(const struct sieve_item* p_sieve, int sieve_length)
{
	//Last element in the sieve.
	const struct sieve_item* const p_last_candidate = &p_sieve[sieve_length-1];

	//The highest possible divisor to check.
	double number_to_check_limit = sqrt((double)p_last_candidate->prime_candidate);

	//Tracks which candidate we are currently excluding multiples of.
	struct sieve_item* p_candidate_tracker = p_sieve;

	//Count the p_primes.
	int prime_counter = 0;

	//Loop through unchecked candidates.
	while (p_candidate_tracker->prime_candidate <= number_to_check_limit)
	{
		//When you find one that is unchecked it must be prime.
		//The first one is always unchecked
		prime_counter++;

		//Mark all the multiples.
		
		//If the gaps between numbers are 1 this moves from a to a+prime_candidate, if the gaps
		//are 2 this moves from a to a + 2*prime_candidate
		struct sieve_item* p_next_candidate_to_mark = p_candidate_tracker + p_candidate_tracker->prime_candidate;
		while (p_next_candidate_to_mark <= p_last_candidate)
		{
			p_next_candidate_to_mark->is_checked = true;
			p_next_candidate_to_mark += p_candidate_tracker->prime_candidate;
		}

		//Advance to the next unmarked candidate.
		do
		{
			p_candidate_tracker++;
		} while (p_candidate_tracker->prime_candidate <= number_to_check_limit && p_candidate_tracker->is_checked == true);
	}

	//Count remaining p_primes.
	while (p_candidate_tracker <= p_last_candidate)
	{
		if (p_candidate_tracker->is_checked == false)
		{
			prime_counter++;
		}
		p_candidate_tracker++;
	}
	return prime_counter;
}

void copy_primes(const struct sieve_item* p_sieve, int prime_count, int* p_primes)
{
	const struct sieve_item* p_prime_candidates_copy = p_sieve;
	int coppied_prime_counter = 0;
	while (coppied_prime_counter < prime_count)
	{
		if (p_prime_candidates_copy->is_checked == false)
		{
			p_primes[coppied_prime_counter] = p_prime_candidates_copy->prime_candidate;
			coppied_prime_counter++;
		}
		p_prime_candidates_copy++;
	}
}

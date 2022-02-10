/// <summary>
/// Finds prime numbers using the sieve of aristhosthenes.
/// </summary>
/// <param name="max_prime">The value to find all primes up to.</param>
/// <param name="p_primes_length">A pointer to hold the length of the return array.</param>
/// <returns>An array containing all the required primes.</returns>
int* aristhothenes_sieve(int max_prime, int* p_primes_length);

/// <summary>
/// Finds prime numbers using the sieve of aristhosthenes but omitting even numbers from the sieve.
/// </summary>
/// <param name="max_prime">The value to find all primes up to.</param>
/// <param name="p_primes_length">A pointer to hold the length of the return array.</param>
/// <returns>An array containing all the required primes.</returns>
int* aristhothenes_sieve_advanced(int max_prime, int* p_primes_length);

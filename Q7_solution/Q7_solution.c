#include <stdio.h>
#include <stdlib.h>

#include "sieve.h"
#include "primePrinting.h"

/// <summary>
/// Reads an integer from the user.
/// </summary>
/// <returns>The integer read from the user.</returns>
int read_int();

int main() {
    printf("Please enter a maximum prime number:");
    int max_prime = read_int();

    //to hold the length of the array
    int primes_length = 0;
    int* p_primes_length = &primes_length;

    const int* p_primes = aristhothenes_sieve(max_prime, p_primes_length);
    printf("All primes less than or equal to %d using standard sieve of aristhothenes \n", max_prime);
    print_primes(p_primes, *p_primes_length);

    p_primes = aristhothenes_sieve_advanced(max_prime, p_primes_length);
    printf("All primes less than or equal to %d using advanced sieve of aristhothenes \n", max_prime);
    print_primes(p_primes, *p_primes_length);
}

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



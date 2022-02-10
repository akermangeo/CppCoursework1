#include <stdio.h>

#include "sieve.h"
#include "primePrinting.h"



int main() {
    int max_prime = 10;

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



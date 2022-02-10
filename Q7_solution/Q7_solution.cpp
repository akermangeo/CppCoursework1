#include "sieve.h"


int main() {
    int max_prime = 10000;

    //to hold the length of the array

    int primesLength = 0;
    int* p_primes_length = &primesLength;

    int* p_primes = aristhothenes_sieve_advanced(max_prime, p_primes_length);

}



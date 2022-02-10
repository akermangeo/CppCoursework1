#include <stdio.h>

#include "sieve.h"


int main() {
    int N = 10000;

    //to hold the length of the array

    int primesLength = 0;
    int* p_primes_length = &primesLength;

    int* p_primes = aristhothenes_sieve(N, p_primes_length);
}



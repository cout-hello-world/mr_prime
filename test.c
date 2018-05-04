// Generate part of table at
// https://primes.utm.edu/lists/2small/0bit.html
#include <stdio.h>
#include <stdint.h>
#include "mr_prime.h"

int main(void)
{
	printf("n: ten least k's for which 2^n-k is prime.\n");
	for (unsigned n = 8; n != 65; ++n) {
		printf("%u: ", n);
		int count = 0;
		unsigned k = 1;
		while (count != 10) {
			uint64_t candidate;
			if (n != 64) {
				candidate = (1ULL << n) - k;
			} else {
				candidate = 0ULL - k;
			}
			if (mr_prime(candidate)) {
				if (count != 9) {
					printf("%u, ", k);
				} else {
					printf("%u\n", k);
				}
				++count;
			}
			++k;
		}
	}
}

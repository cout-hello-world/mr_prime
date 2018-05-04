// Generate part of table at
// https://primes.utm.edu/lists/2small/0bit.html
#include <stdio.h>
#include <stdint.h>
#include "mr_prime.h"

int main(void)
{
	printf("n: ten least k's for which 2^n-k is prime\n");
	for (int n = 8; n != 65; ++n) {
		printf("%d: ", n);
		int count = 0;
		unsigned k = 1;
		while (count != 10) {
			if (mr_prime((1ULL << n) - k)) {
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

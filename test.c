#include <stdio.h>
#include <stdint.h>
#include "mr_prime.h"

int main(void)
{
	for (uint64_t i = 1; i != 100000; ++i) {
		if (mr_prime(0 - i)) {
			printf("%lu\n", i);
		}
	}
}

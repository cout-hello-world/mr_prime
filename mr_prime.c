// This code is placed in the public domain by its author, Henry Elliott
// Compile with C99/C11 compiler with support for __int128 extension
//
// Based on:
// https://math.stackexchange.com/questions/2481148/primality-testing-for-64-bit-numbers
// https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Deterministic_variants
// https://en.wikipedia.org/wiki/Modular_exponentiation#Left-to-right_binary_method
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

static const unsigned a_arr[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
static const size_t a_arr_len = 12;

static uint64_t mod_exp(uint64_t b, uint64_t e, uint64_t m)
{
	uint64_t result = 1;
	unsigned __int128 base = b % m;
	while (e) {
		if (e % 2) {
			result = (result * base) % m;
		}
		e /= 2;
		base = (base * base) % m;
	}
	return result;
}

bool mr_prime(const uint64_t n)
{
	unsigned s = 0;
	uint64_t d = n;
	if (n % 2 == 0 || n == 1) {
		return false;
	}

	--d;
	while (d % 2 == 0) {
		d /= 2;
		++s;
	}

	for (size_t i = 0; i != a_arr_len; ++i) {
		unsigned a = a_arr[i];
		for (unsigned r = 0; r != s; ++r) {
			if (mod_exp(a, d, n) == 1 || mod_exp(a, (1 << r) * d, n) == n - 1) {
				goto could_be_prime;
			}
		}
		return false;
	could_be_prime:
		;
	}
	return true;
}

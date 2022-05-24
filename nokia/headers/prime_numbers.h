#pragma once

#include <vector>

/*Write a function that calculates the first N prime numbers and put these numbers in the array passed to it.*/

//O(N * N)
bool is_prime(int number);

void find_prime_numbers(int n, std::vector<int>& primes)
{
	if (n <= 0) return;

	primes.push_back(2);
	for (int i(3); primes.size() < n; i+=2 )
		if (is_prime(i))
			primes.push_back(i);
}

bool is_prime(int number)
{
	if (number <= 1) return false;

	for (int i(2); i < number; ++i)
		if (number % i == 0) return false;

	return true;
}
#pragma once

#include <vector>
#include <algorithm>

int count_primes(const int& n)
{
	if (n < 2) return 0;

	std::vector<bool> numbers(n, true);
	for (int i(2); i * i < n; ++i)
	{
		if (numbers[i])
		{
			for (int j(i); j * i < n; ++j)
				numbers[j * i] = false;
		}
	}

	return std::count_if(numbers.begin() + 2, numbers.end(), [](const bool& item) { return item; });
}

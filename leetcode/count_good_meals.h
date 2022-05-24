#pragma once

#define MOD 1000000007

#include <vector>
#include <unordered_map>

using std::vector;


//O(n)
int count_good_meals(const vector<int>& input)
{
	std::unordered_map<int, int> map;

	int counter(0);
	for (int i(0); i < input.size(); ++i)
	{
		int power = 1;

		for (int j(0); j < 22; ++j)
		{
			if (map.count(power - input[i]))
			{
				counter += map[power - input[i]];
				counter = counter % MOD;
			}

			power *= 2;
		}

		map[input[i]]++;
	}

	return counter;
}
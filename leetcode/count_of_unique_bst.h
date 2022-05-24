#pragma once

#include <vector>

using std::vector;

//O(n * n) 
int count_unique_bst(int n)
{
	vector<int> memo(n + 1);
	memo[0] = 1;
	memo[1] = 1;

	for (int i(2); i <= n; ++i)
		for (int j(0); j < n; ++j)
			memo[i] += memo[j] * memo[i - 1 - j];

	return memo[n];
}

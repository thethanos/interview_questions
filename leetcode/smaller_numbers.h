#pragma once

#define MAX_NUM 100
#define SIZE MAX_NUM + 1

#include <vector>

using std::vector;


//O(n)
vector<int> smaller_numbers_array(vector<int> nums)
{
	int smaller[SIZE];
	memset(smaller, 0, SIZE * sizeof(int));

	for (int i(0); i < nums.size(); ++i)
		smaller[nums[i]]++;

	for (int i(1); i < SIZE; ++i)
		smaller[i] += smaller[i - 1];

	for (int i(0); i < nums.size(); ++i)
	{
		if (nums[i])
			nums[i] = smaller[nums[i] - 1];
		else
			nums[i] = 0;
	}

	return nums;
}
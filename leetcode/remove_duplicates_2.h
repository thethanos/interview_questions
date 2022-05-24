#pragma once

#include <vector>

using std::vector;

int remove_duplicates(vector<int>& input)
{
	if (input.size() < 3) return input.size();

	int slow(2), fast(2);
	while (fast < input.size())
	{
		if (input[slow - 2] != input[fast])
			input[slow++] = input[fast];

		fast++;
	}

	return slow;
}
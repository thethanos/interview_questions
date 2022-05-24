#pragma once

#include <vector>
#include <algorithm>

using std::vector;

vector<vector<int>> sum(vector<int> input)
{
	std::sort(input.begin(), input.end());

	vector<vector<int>> res;
	for (int i(0); i < (int)input.size() - 2; ++i)
	{
		if (i > 0 && input[i - 1] == input[i]) continue;

		int j = i + 1;
		int k = input.size() - 1;
		int target = 0 - input[i];

		while (j < k)
		{
			if (input[j] + input[k] == target)
			{
				res.push_back(vector<int>{input[i], input[j], input[k]});
				while (j < k && input[j] == input[j + 1]) { j++; };
				while (j < k && input[k] == input[k - 1]) { k--; };
				j++;
				k--;
				continue;
			}

			if (input[j] + input[k] > target)
				--k;
			else
				++j;
		}
	}

	return res;
}
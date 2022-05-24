#pragma once

#include <vector>
#include <unordered_map>

//O(n)
size_t count_good_pairs(const std::vector<int>& nums)
{
	std::unordered_map<int, int> umap;
	for (int i(0); i < nums.size(); ++i)
		umap[nums[i]]++;

	size_t res(0);
	for (const auto& item : umap)
		res += (item.second - 1) * item.second / 2;

	return res;
}
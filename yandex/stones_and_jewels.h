#pragma once

#include <fstream>
#include <string>
#include <unordered_set>

using std::string;

void read_file(string& jewels, string& stones)
{
	std::fstream fst("c:/users/origi/onedrive/desktop/input.txt", std::ios_base::in);

	fst >> jewels >> stones;
}

size_t count_stones(string& jewels, string& stones)
{
	std::unordered_set<char> set{ jewels.begin(), jewels.end() };
	
	size_t res(0);
	for (auto& item : stones)
		if (set.count(item))
			res++;

	return res;
}
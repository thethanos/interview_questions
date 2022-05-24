#pragma once

#include <fstream>
#include <vector>

using std::vector;

vector<int> read_file()
{
	int count(0), temp(0);
	std::fstream fst("c:/users/origi/onedrive/desktop/input.txt", std::ios_base::in);
	fst >> count;
	
	vector<int> res(count);
	for (int i(0); i < count; ++i)
		fst >> res[i];

	return res;
}

size_t get_num_count(const vector<int>& data)
{
	int counter(0), max_len(0);
	for (auto& item : data)
	{
		if (!item)
		{
			max_len = std::max(max_len, counter);
			counter = 0;
		}
		else
			counter++;
	}

	return max_len;
}
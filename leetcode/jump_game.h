#pragma once

#include <vector>
using std::vector;

bool jump_game(const vector<int>& data)
{
	int last_pos = data.size() - 1;
	for (int i(data.size() - 1); i >= 0; i--)
	{
		if (i + data[i] >= last_pos)
			last_pos = i;
	}

	return last_pos == 0;
}
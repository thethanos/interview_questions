#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

//O(n * n)
size_t move_count(int cur_box, const string& boxes);

vector<int> min_count_of_operations_1(const string& boxes)
{
	vector<int> res(boxes.size());
	for (size_t i(0); i < boxes.size(); ++i)
		res[i] = move_count(i, boxes);

	return res;
}

size_t move_count(int cur_box, const string& boxes)
{
	size_t res(0);
	for (int i(0); i < boxes.size(); ++i)
	{
		if (i != cur_box && boxes[i] == '1')
			res += abs(i - cur_box);
	}

	return res;
}

//O(n)
vector<int> min_count_of_operations_2(const string& boxes)
{
	vector<int> res(boxes.size());
	
	int steps(0), left(0), right(0);
	for (int i(0); i < boxes.size(); ++i)
	{
		if (boxes[i] == '1')
		{
			steps += i;
			right++;
		}
	}

	for (int i(0); i < boxes.size(); ++i)
	{
		res[i] = steps;

		if (boxes[i] == '1')
		{
			right--;
			left++;
		}

		steps += left;
		steps -= right;
	}


	return res;
}
#pragma once

#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;

size_t read_file()
{
	size_t count(0);
	std::fstream fst("c:/users/origi/onedrive/desktop/input.txt", std::ios_base::in);

	fst >> count;
	return count;
}

void generate(vector<string>& res, int n, const string& str, int open, int close)
{
	if (str.length() == n * 2)
	{
		res.push_back(str);
		return;
	}

	if (open < n)
		generate(res, n, str + '(', open + 1, close);
	if (close < open)
		generate(res, n, str + ')', open, close + 1);
}
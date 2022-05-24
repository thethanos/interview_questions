#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

void generator(vector<string>& res, int open, int close, const string& str, int n);

vector<string> generateParenthesis(int n)
{
	vector<string> res;
	generator(res, 0, 0, "", n);

	return res;
}

void generator(vector<string>& res, int open, int close, const string& str, int n)
{
	if (str.length() == n * 2)
	{
		res.push_back(str);
		return;
	}

	if (open < n)
		generator(res, open + 1, close, str + '(', n);
	if (close < open)
		generator(res, open, close + 1, str + ')', n);
}
#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

void generate_combinations(const string& digits, vector<string>& res, int level, const string& str, const vector<string>& mapping);

vector<string> get_combinations(string digits)
{
	vector<string> res;
	if (digits.empty()) return res;

	vector<string> mapping{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	generate_combinations(digits, res, 0, "", mapping);

	return res;
}

void generate_combinations(const string& digits, vector<string>& res, int level, const string& str, const vector<string>& mapping)
{
	if (level == digits.size())
	{
		res.push_back(str);
		return;
	}

	string letters = mapping[digits[level] - '0'];
	for (int i(0); i < letters.length(); ++i)
		generate_combinations(digits, res, level + 1, str + letters[i], mapping);
}
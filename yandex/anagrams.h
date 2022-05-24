#pragma once

#include <string>
#include <fstream>
#include <unordered_set>

using std::string;

void read_file(string& str1, string& str2)
{
	std::fstream fst("c:/users/origi/onedrive/desktop/input.txt", std::ios_base::in);

	fst >> str1 >> str2;
}

bool is_anagrams(const string& str1, const string& str2)
{
	std::unordered_set<char> set1{ str1.begin(), str1.end() }, set2{str2.begin(), str2.end()};

	return set1 == set2;
}
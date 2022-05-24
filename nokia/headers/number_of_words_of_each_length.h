#pragma once

#include <map>
#include <string>
#include <sstream>

/*Write a function that counts the number of words in the text for each word length.*/

//O(N * N)
std::map<size_t, size_t> count_words_of_each_length(std::string text)
{
	std::map<size_t, size_t> res;

	if (text.empty()) return res;

	auto iter = std::remove_if(text.begin(), text.end(), [](const char& ch) { return !::isalpha(ch) && !::isspace(ch); });
	text.erase(iter, text.end());

	std::istringstream ist{ text };
	std::string temp;
	while (!ist.eof())
	{
		ist >> temp;
		res[temp.size()]++;
	}

	return res;
}
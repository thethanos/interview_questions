#pragma once

#include <string>
#include <algorithm>

using std::string;

int longest_sunstring(const string& str)
{
	if (str.empty()) return 0;

	char chars[256];
	memset(chars, 0, 256);

	int i(0), j(0);
	int max_len = 1;
	while (j < str.size())
	{
		if (!chars[str[j]])
		{
			chars[str[j]] = true;
			++j;
		}
		else
		{
			chars[str[i]] = false;
			++i;
		}

		max_len = std::max(max_len, j - i);
	}

	return max_len;
}
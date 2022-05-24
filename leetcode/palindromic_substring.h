#pragma once

#include <string>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;

//checks if the given string is a palindrome
bool is_palindrome(const string& str)
{
	return std::equal(str.rbegin(), str.rend(), str.begin());
}

//returns true if there is a palindrome of length pal_len
int find_palindrome(int pal_len, const string& str)
{
    for (int i = 0; i + pal_len <= str.length(); i++)
    {
        if (is_palindrome(str.substr(i, pal_len)))
            return i;
    }
    return -1;
}


// O(N^3)
string longest_palimdromic_substr_1(const string& str)
{
	int best_len(0);
	string best_str, substr;

	int length = str.length();

	for (int i(0); i < length; ++i)
	{
		for (int j(length); j >= 0; --j)
		{
			substr = str.substr(i, j);
			if (best_len < substr.length() && is_palindrome(substr))
			{
				best_str = substr;
				best_len = substr.length();
			}
		}
	}

	return best_str;
}

//O(log(N) * N^2)
string longest_palindromic_substr_2(const string& str)
{
    size_t best_len(0);
    string best_match;

    size_t length = str.length();

    for (int i : {0, 1})
    {
        int low = 1, high = length;

        if (low % 2 != i)
            low++;

        if (high % 2 != i)
            high--;

        while (low <= high)
        {
            int palindrome_len = (low + high) / 2;
            
            if (palindrome_len % 2 != i)
                palindrome_len++;

            int start_index = find_palindrome(palindrome_len, str);

            if (start_index != -1)
            {
                if (palindrome_len > best_len)
                {
                    best_len = palindrome_len;
                    best_match = str.substr(start_index, palindrome_len);
                }
                low = palindrome_len + 2;
            }
            else
                high = palindrome_len - 2;
        }
    }

    return best_match;
} 

//O(N^2)
string longest_palindromic_substr_3(const string& str)
{
    size_t length = str.length();

    vector<vector<bool>> table(length, vector<bool>(length));
    table[0][0] = true;

    int maxLength(1), start(0);
    for (int i(1); i < length; ++i)
    {
        table[i][i] = true;
        if (str[i-1] == str[i])
        {
            table[i - 1][i] = true;
            maxLength = 2;
            start = i - 1;
        }
    }

    for (int gap(3); gap <= length; ++gap)
    {
        int j(0);
        for (int i(0); i+gap-1 < length; ++i)
        {
            j = i + gap-1;
            if (table[i + 1][j - 1] && str[i] == str[j])
            {
                table[i][j] = true;

                if (gap > maxLength)
                {
                    maxLength = gap;
                    start = i;
                }
            }
        }
    }

    return str.substr(start, maxLength);
}
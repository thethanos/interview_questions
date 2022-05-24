#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

//O(N^2)
string longest_common_prefix(const vector<string>& strs)
{
    if (strs.empty()) return "";

    string prefix;
    for (int i(0); i < strs[0].size(); ++i)
    {
        char ch = strs[0][i];
        for (int j(0); j < strs.size(); ++j)
        {
            if (i >= strs[j].size() || strs[j][i] != ch)
                return prefix;
        }

        prefix.push_back(ch);
    }

    return prefix;
}
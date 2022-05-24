#pragma once

#include <vector>

using std::vector;

//O(log(N))

vector<int> binary(const vector<int>& data, int target, int begin, int end);

vector<int> searchRange(const vector<int>& nums, int target)
{
    return binary(nums, target, 0, nums.size() - 1);
}

vector<int> binary(const vector<int>& data, int target, int begin, int end)
{
    if (begin > end) return vector<int>{-1, -1};

    int pos = (begin + end) / 2;
    if (data[pos] == target)
    {
        vector<int> res{ pos, pos };
        for (int i(pos - 1); i >= 0; --i)
            if (data[i] == target)
                res[0] = i;

        for (int i(pos + 1); i < data.size(); ++i)
            if (data[i] == target)
                res[1] = i;

        return res;
    }

    if (data[pos] < target)
        return binary(data, target, pos + 1, end);
    else
        return binary(data, target, begin, pos - 1);
}
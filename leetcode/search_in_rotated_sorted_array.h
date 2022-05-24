#pragma once

#include <vector>

using std::vector;

//O(log(N))
int search(vector<int>& data, int target)
{
    if (data.empty()) return -1;

    int left = 0;
    int right = data.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (data[mid] > data[right])
            left = mid + 1;
        else
            right = mid;
    }

    int start = left;
    left = 0;
    right = data.size() - 1;

    if (target >= data[start] && target <= data[right])
        left = start;
    else
        right = start;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (data[mid] == target)
            return mid;

        if (data[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

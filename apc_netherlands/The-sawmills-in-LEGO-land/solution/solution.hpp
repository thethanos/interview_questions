#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>
#include <list>
#include <set>

/*
    Introduction: The sawmills in LEGO land
    Daily woodcutters of LEGO land cut trees in the mountains. Every tree trunk is precise 1, 2, 3, etc blocks in length.
    This is LEGO land you know! Trees are mere simple blocks. The weak spot of a tree is the trunk, so woodcutters cut
    the tree from the ground. Then the leaves are removed. At the end of the day the woodcutters throw the tree
    trunks in any order they like into the river.
    More downstream there is a sawmill to where the tree trunks will float. The river has the same width as the tree
    trunks and therefore tree trunks cannot overtake each other. So, the first tree trunk the woodcutters throw into
    the river will arrive first at the sawmill. The space between tree trunks is neglectable. In LEGO land everything fits
    very precise.
    When the woodcutters return from their work, they will turn the sawmill on. Unfortunately, the machine is old,
    and the speed cannot be regulated anymore. The LEGO replacement kit is unfortunately obsolete. The mechanics
    are broken, so every 3 blocks it just makes a cut. So, if the first tree trunk is 4 blocks in length, then it will produce
    sawn wood of length 3 and, the remainder, length 1 for example.
    Unfortunately, by the specific building rules in LEGO land, only sawn wood of length 2 is used by the carpenters. To
    be more precise:
    • Sawn wood of length of 1 has a profit of -1 LEC. It costs money to get rid of it.
    • Sawn wood of length 2 has a profit of +3 LEC.
    • Luckily, sawn wood of length 3 can still be sold for +1 LEC as it can be shortened by the carpenters
    themself.

    Exercise:
    The input describes several test cases. The first line of input for each test case contains a single integer Z, the
    number of sawmills (each is connected to its own river) in the test case. This is followed by Z lines, each describing
    the tree trunks. The first number in each line is the number E of tree trunks that are cut. Following it are E strict
    positive integers, indicating the length (in blocks) of the tree trunks. The input is terminated by a description
    starting with Z = 0. This description should not be processed.
    For each test case, print the case number (1, 2, ...). Then print two lines, the first containing the maximum profit
    the woodcutters can achieve. The second line should specify the order the woodcutters should throw the trees
    into the river between squares. Whereas the first number represents the first tree trunk to be thrown into the
    river. Idem, the last number is the last tree trunk thrown into the river. If this order is not uniquely determined,
    print all possible orders. Remove all duplicates.

    Example input:
    1
    3 2 3 1
    3
    3 1 2 1
    2 1 2
    2 1 4
    0

    Example output:
    Case 1
    Max profit: 4
    Order: [1 3 2] [2 3 1]
    Case 2
    Max profit: 8
    Order: [1 2 1] [2 1 1], [1 2] [2 1], [1 4]
*/

using std::cin;
using std::cout;
using std::vector;
using std::list;
using std::pair;
using std::set;
using std::unordered_set;

// vector comparator for set
struct cmp
{
    bool operator()(pair<int, vector<int>> pair1, pair<int, vector<int>> pair2)
    {
        return !equal(pair1.second.begin(), pair1.second.end(), pair2.second.begin());
    }
};

// returns profit of the certain trunc
int get_profit(int val);

// calculate profit of a bunch of truncs
int calculate_profit(const vector<int>& data);

// generate all trunc combinations
void generate(const vector<int>& input, vector<int>& temp, unordered_set<int>& st, set<pair<int, vector<int>>, cmp>& res, int& max_profit);

// read input from stdin
auto read_input();

// process data read from stdin
void process(); 

// print a sawmill output
void print(vector<vector<int>>& data);
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

void generate(const vector<int>& cands, int target, int level, vector<vector<int>>& res, vector<int>& cand);

vector<vector<int>> combination_sum(vector<int>& cands, int target)
{
	sort(cands.begin(), cands.end());
	cands.erase(std::unique(cands.begin(), cands.end()), cands.end());

	vector<int> cand;
	vector<vector<int>> res;
	generate(cands, target, 0, res, cand);

	return res;
}

void generate(const vector<int>& cands, int target, int level, vector<vector<int>>& res, vector<int>& cand)
{
	if (target == 0)
	{
		res.push_back(cand);
		return;
	}

	while (level < cands.size() && target - cands[level] >= 0)
	{
		cand.push_back(cands[level]);
		generate(cands, target - cands[level], level, res, cand);
		level++;

		cand.pop_back();
	}
}
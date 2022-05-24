#pragma once

#include <vector>
#include <algorithm>

using std::vector;

struct TreeNode
{
	TreeNode(int val) :val(val) {}

	struct TreeNode* leftChild = nullptr;
	struct TreeNode* rightChild = nullptr;

	int val;
};

/*Write a function that calculates the depth of the tree. The solution shall return all paths in the tree that have such depth*/

//O(N)
void dfs_rec(TreeNode* node, vector<vector<int>>& res, vector<int> path, size_t& max_length);

vector<vector<int>> get_longest_paths(TreeNode* root)
{
	std::vector<vector<int>> temp, res;
	if (!root) return res;

	size_t max_length(0);
	dfs_rec(root, temp, vector<int>{}, max_length);

	std::copy_if(temp.begin(), temp.end(), std::back_inserter(res), [&max_length](const auto& item) { return item.size() == max_length; });
	return res;
}

void dfs_rec(TreeNode* node, vector<vector<int>>& res, vector<int> path, size_t& max_length)
{
	if (!node) return;

	path.push_back(node->val);
	if (!node->leftChild && !node->rightChild)
	{
		max_length = std::max(max_length, path.size());
		res.push_back(path);
		return;
	}

	dfs_rec(node->leftChild, res, path, max_length);
	dfs_rec(node->rightChild, res, path, max_length);
}
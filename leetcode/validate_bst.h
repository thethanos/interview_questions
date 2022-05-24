#pragma once

#include <stdint.h>
#include <stack>

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

bool validate_bst(TreeNode* root)
{
	long long max_left = INT64_MIN;

	std::stack<TreeNode*> st;

	TreeNode* cur_node = root;
	while (!st.empty() || cur_node)
	{
		while (cur_node)
		{
			st.push(cur_node);
			cur_node = cur_node->left;
		}

		cur_node = st.top();
		st.pop();

		if (cur_node->val <= max_left) return false;
		max_left = cur_node->val;

		cur_node = cur_node->right;
	}

	return true;
}
#pragma once

#include <gtest/gtest.h>

#include "max_depth_of_the_tree.h"

void add_node(TreeNode*& node, int value)
{
	if (!node)
	{
		node = new TreeNode(value);
		return;
	}

	if (value < node->val)
		add_node(node->leftChild, value);
	else
		add_node(node->rightChild, value);
}

void fill_from_vector(TreeNode*& root, const std::vector<int>& input)
{
	for (const auto& item : input)
		add_node(root, item);
}

bool compare_result(const vector<vector<int>>& res1, const vector <vector<int>>& res2)
{
	if (res1.size() != res2.size()) return false;

	bool flag = true;
	for (auto iter1(res1.begin()), iter2(res2.begin()); iter1 != res1.end() && flag; ++iter1, ++iter2)
		flag = std::equal(iter1->begin(), iter1->end(), iter2->begin());

	return flag;
}

TEST(MaxDepthOfTheTree, MaxDepthOfTheTree)
{
	TreeNode* tree1 = nullptr, *tree2 = nullptr, *tree3 = nullptr;

	vector<vector<int>> correct_res1;
	vector<vector<int>> correct_res2{ {8, 6, 3}, {8, 6, 7}, {8, 12, 10}, {8, 12, 14} };
	vector<vector<int>> correct_res3{ {8, 6, 3, 4},};
	
	fill_from_vector(tree1, {});
	auto output1 = get_longest_paths(tree1);
	ASSERT_TRUE(compare_result(output1, correct_res1));

	fill_from_vector(tree2, {8, 6, 12, 3, 7, 10, 14});
	auto output2 = get_longest_paths(tree2);
	ASSERT_TRUE(compare_result(output2, correct_res2));

	fill_from_vector(tree3, { 8, 6, 12, 3, 4, 7, 10, 14 });
	auto output3 = get_longest_paths(tree3);
	ASSERT_TRUE(compare_result(output3, correct_res3));
}
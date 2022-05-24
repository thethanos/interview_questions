#pragma once

#include <vector>
#include <gtest/gtest.h>

#include "remove_every_fifth_element.h"

void add_node(List*& list, int value)
{
	List* temp = list;
	list = new List(value);

	list->next = temp;
}

void fill_from_vector(List*& head, const std::vector<int>& input)
{
	for (const auto& item : input)
		add_node(head, item);
}

void to_vector(List* head, std::vector<int>& res)
{
	if (!head) return;

	res.push_back(head->val);
	to_vector(head->next, res);
}

TEST(RemoveEveryFifthElement, RemoveEveryFifthElement)
{
	List* list0 = nullptr, *list5 = nullptr, *list10 = nullptr;

	std::vector<int> output0,  correct_res0;
	std::vector<int> output5,  correct_res5  = { 0, 1, 2, 3 };
	std::vector<int> output10, correct_res10 = { 0, 1, 2, 3, 5, 6, 7, 8 };

	fill_from_vector(list0,  {});
	fill_from_vector(list5,  { 4, 3, 2, 1, 0 });
	fill_from_vector(list10, { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 });

	remove_every_fifth_element(list0);
	to_vector(list0, output0);
	ASSERT_TRUE(std::equal(output0.begin(), output0.end(), correct_res0.begin()));

	remove_every_fifth_element(list5);
	to_vector(list5, output5);
	ASSERT_TRUE(std::equal(output5.begin(), output5.end(), correct_res5.begin()));

	remove_every_fifth_element(list10);
	to_vector(list10, output10);
	ASSERT_TRUE(std::equal(output10.begin(), output10.end(), correct_res10.begin()));

};
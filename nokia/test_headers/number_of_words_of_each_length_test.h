#pragma once

#include <gtest/gtest.h>

#include "number_of_words_of_each_length.h"

TEST(NumberOfWords, NumberOfWords)
{
	std::map<size_t, size_t> correct_res1{ {1, 1}, {2, 1}, {4, 3} };
	std::map<size_t, size_t> correct_res2{ {2, 2}, {3, 1}, {4, 1}, {5, 3}, {6, 1}, {8, 2} };
	std::map<size_t, size_t> correct_res3{ {2, 1}, {4, 1}, {5, 1}, {6, 1} };

	auto output1 = count_words_of_each_length(std::string{"This is a test case"});
	ASSERT_TRUE(std::equal(output1.begin(), output1.end(), correct_res1.begin()));

	auto output2 = count_words_of_each_length(std::string{"Lorem Ipsum is simply dummy text of the printing industry."});
	ASSERT_TRUE(std::equal(output2.begin(), output2.end(), correct_res2.begin()));

	auto output3 = count_words_of_each_length(std::string{"Nokia, please, hire me!" });
	ASSERT_TRUE(std::equal(output3.begin(), output3.end(), correct_res3.begin()));
}
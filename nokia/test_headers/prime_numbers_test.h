#pragma once

#include <gtest/gtest.h>

#include "prime_numbers.h"

TEST(PrimeNumbers, IsPrime)
{
	ASSERT_TRUE(is_prime(2));
	ASSERT_TRUE(is_prime(89));
	ASSERT_TRUE(is_prime(127));

	ASSERT_FALSE(is_prime(0));
	ASSERT_FALSE(is_prime(-5));
	ASSERT_FALSE(is_prime(90));
}

TEST(PrimeNumbers, FindNumbers)
{
	std::vector<int> output0,  correct_res0;
	std::vector<int> output1,  correct_res1  = { 2 };
	std::vector<int> output5,  correct_res5  = { 2, 3, 5, 7, 11 };
	std::vector<int> output10, correct_res10 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

	find_prime_numbers(0,  output0);
	ASSERT_TRUE(std::equal(output0.begin(), output0.end(), correct_res0.begin()));

	find_prime_numbers(1,  output1);
	ASSERT_TRUE(std::equal(output1.begin(), output1.end(), correct_res1.begin()));

	find_prime_numbers(5,  output5);
	ASSERT_TRUE(std::equal(output5.begin(), output5.end(), correct_res5.begin()));

	find_prime_numbers(10, output10);
	ASSERT_TRUE(std::equal(output10.begin(), output10.end(), correct_res10.begin()));
}
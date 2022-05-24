#pragma once

#include <gtest/gtest.h>

#include "min_and_max_numbers.h"

TEST(MinMaxNumbers, MinMaxNumbers)
{
	auto res0 = find_min_max_numbers(0);
	ASSERT_EQ(res0.first, 0);
	ASSERT_EQ(res0.second, 0);

	auto res10 = find_min_max_numbers(10);
	ASSERT_EQ(res10.first, 3);
	ASSERT_EQ(res10.second, 3221225472);

	auto res255 = find_min_max_numbers(255);
	ASSERT_EQ(res255.first, 255);
	ASSERT_EQ(res255.second, 4278190080);
}
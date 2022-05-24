#pragma once

/*Write a function that takes a 32-bit unsigned integer number and returns the maximum and minimum 32-bit unsigned integer
numbers which can be obtained using the same number of bits set to 1 as in the taken number*/

//O(N)
std::pair<uint32_t, uint32_t> find_min_max_numbers(uint32_t input)
{
	if (!input) return std::make_pair(0, 0);

	uint32_t count(0);
	for (int i(0); i < 32; ++i)
		if (input & (1 << i))
			count++;
	
	uint32_t min(0), max(0);
	for (uint32_t i(0); i < count; ++i)
	{
		min |= (1 << i);
		max |= (1 << (31-i));
	}

	return std::make_pair(min, max);
}
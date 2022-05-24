#pragma once

#include <iostream>
#include <fstream>

void remove_duplicates()
{
	std::fstream fst("c:/users/origi/onedrive/desktop/input.txt", std::ios_base::in);

	int prev(-1), cur(0), count(0);
	fst >> count;
	
	for (int i(0); i < count; ++i)
	{
		fst >> cur;
		if (prev != cur)
		{
			prev = cur;
			std::cout << cur << std::endl;
		}
	}
}
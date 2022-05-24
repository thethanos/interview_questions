#pragma once

int divide(int dividend, int divisor)
{
	if (dividend == INT32_MIN && divisor == -1)
		return INT32_MAX;

	uint8_t sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

	long long dvd = abs(dividend);
	long long dvs = abs(divisor);
	long long res(0);

	for (int i(31); i >= 0; --i)
	{
		if (dvd >= (dvs << i))
		{
			dvd -= (dvs << i);
			res += (1 << i);
		}
	}

	return res * sign;
}
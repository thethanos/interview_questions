#pragma once

double custom_pow(double x, int n)
{
	if (x == 0) return 0;
	if (n == 0) return 1;

	double temp = custom_pow(x, n/2);
	if (n % 2 == 0) return temp * temp;

	if (n > 0)
		return x* temp* temp;
	else
		return temp* temp / x;
}
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int digits_sum(int num, int base)
{
	int sum = 0;
	int arr[32] = { 0, };
	int i = -1;

	while (num != 0)
	{
		++i;
		sum += num % base;
		num = num / base;
	}


	return sum;
}

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a == b)
		return a;

	int r = 0;
	if (a > b)
	{
		while (b != 0)
		{
			r = b;
			b = a % b;
			a = r;
		}
		return a;
	}
	else
	{
		while (a != 0)
		{
			r = a;
			a = b % a;
			b = r;
		}

		return b;
	}
}

int power(int a, unsigned n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return a;
	}

	int helper = a;

	for (int i = 2; i <= n; i++)
	{
		a = a*helper;
	}
	return a;
}

bool green_num(int n)
{
	int sum = 0;
	int k = n;
	while (n != 0)
	{
		int a = n % 10;
		sum += power(a, 3); //izpolzvam f-qta si za stepenuvane
		n /= 10;
	}
	if (k == sum)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int green_num_sum(int n, int m)
{
	int sum = 0;
	if (m > n)
	{
		for (int i = n; i <= m; i++)
		{
			if (green_num(i))
			{
				sum += i;
			}
		}
	}
	else
	{
		for (int i = m; i <= n; i++)
		{
			if (green_num(i))
			{
				sum += i;
			}
		}
	}
	return sum;
}

int numbers_sum(int n)
{
	int sum = 0;
	while (n != 0)
	{
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

bool red_num(int n)
{
	int k = 0;
	while (k*numbers_sum(n) < n)
	{
		k++;
	}

	if (k*numbers_sum(n) == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int red_num_sum(int n, int m)
{
	int sum = 0;
	if (n > m)
	{
		for (int i = m; i <= n; i++)
		{
			if (red_num(i))
			{
				sum += i;
			}
		}
	}
	else
	{
		for (int i = n; i <= m; i++)
		{
			if (red_num(i))
			{
				sum += i;
			}
		}
	}

	return sum;
}

int difference_red_green_nums(int n, int m)
{
	int difference = 0;
	if (n > m)
	{
		for (int i = m; i < n; i++)
		{
			difference = red_num_sum(n, m) - green_num_sum(n, m);
		}
	}
	else
	{
		for (int i = n; i < m; i++)
		{
			difference = red_num_sum(n, m) - green_num_sum(n, m);
		}
	}

	if (difference < 0)
	{
		return -difference;
	}
	else
	{
		return difference;
	}
}

int fact(int n)
{
	int prod = 1;
	for (int i = 1; i <= n;i++)
	{
		prod = prod*i;
	}
	return prod;
}

double my_cos(double x, int n)
{
	double sum = 0;

	for (int i = 0; i <= n; i++)
	{
		sum = sum + pow(-1, i)*(pow(x, 2 * i) / fact(2 * i));
	}

	return sum;
}

double my_sin(double x, int n)
{
	double sum = 0;
	double cos_x = my_cos(x, n);

	sum = sqrt(1 - cos_x*cos_x);

	return sum;
}

double my_tg(double x, int n)
{
	double sum = 0;
	double sin_x = my_sin(x, n);
	double cos_x = my_cos(x, n);

	sum = sin_x / cos_x;

	return sum;
}

double my_cotg(double x, int n)
{
	double sum = 0;
	double tg_x = my_tg(x, n);

	sum = 1 / tg_x;

	return sum;
}

int main()
{

	return 0;
}

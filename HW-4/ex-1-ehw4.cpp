#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;


int is_prime(int n)
{
	int limit = sqrt(n);
	bool prime = true;

	if (n % 2 == 0)
	{
		prime = false;
	}

	for (int i = 3; i <= limit; i += 2)
	{
		if (n % i == 0)
		{
			prime = false;
		}
	}

	if (prime)
	{
		return n;
	}

}

int main()
{
	int n;
	cin >> n;

	if (n < 3)
	{
		cout << "Incorrect input!" << endl;
		return 1;
	}

	if (n % 2 != 0)
	{
		cout << "Are you joking with me, Euler? This number is not even!" << endl;
		return 1;
	}

	for (int i = 2; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (is_prime(i) && is_prime(j))
			{
				if (i + j == n)
				{
					cout << "(" << i << ", " << j << ")" << endl;
				}
			}
		}
	}
	cout << endl;



	return 0;
}

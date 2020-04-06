#include "stdafx.h"
#include <iostream>

using namespace std;

bool is_hamming(int num)
{
	if (num == 1)
	{
		return true;
	}
	if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0)
	{
		while (num % 2 == 0)
		{
			num = num / 2;
		}
		while (num % 3 == 0)
		{
			num = num / 3;
		}
		while (num % 5 == 0)
		{
			num = num / 5;
		}

		if (num == 1)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	else
	{
		return false;
	}
}



int main()
{
	int n;
	cin >> n;

	if (n < 0)
	{
		cout << "Invalid output." << endl;
		return 1;
	}

	if (n == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << 1 << " ";

	int cnt = 0;

	for (int i = 2; i <= n + cnt; i++)
	{
		if (is_hamming(i) == true)
		{
			cout << i << " ";
		}
		else
		{
			cnt++;
		}
	}

	return 0;
}
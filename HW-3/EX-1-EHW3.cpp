#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n < 1 || n>31)
	{
		cout << "Invalid intput." << endl;

		return 0;
	}

	int zapazeni = 0;
	int id_num = 0;

	while (n > 0)
	{
		int i = 0;
		cin >> i;

		if (i > id_num)
		{
			id_num = i;
			zapazeni = zapazeni * 10 + 1;
		}
		else
		{
			zapazeni = zapazeni * 10;
		}
		n--;
	}
	cout << zapazeni << endl;

	return 0;
}
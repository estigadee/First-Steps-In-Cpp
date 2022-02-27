#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int f[1000];
	int deg_f; // stepen na polinoma
	cin >> deg_f;

	for (int i = deg_f; i >= 0; i--)
	{
		cin >> f[i]; // koef pred polinoma
	}

	int derivative; //broq proizvodni
	cin >> derivative;

	int helper = derivative;

	int k = deg_f;
	int cnt = 0;


	while (derivative != 0)
	{
		for (int i = deg_f; i >= 0; i--)
		{
			f[i] = f[i] * k;
			k--;
		}
		++cnt;
		k = deg_f - cnt;
		derivative--;
	}
	derivative = helper;
	int current_deg = (deg_f + 1) - derivative;

	while (current_deg != 0)
	{

		cout << f[deg_f];
		if (k > 0)
		{
			cout << "*x^" << k;
		}
		if (1 - current_deg != 0 && f[deg_f] > 0)
		{
			cout << " + ";
		}

		k--;
		deg_f--;
		current_deg--;
	}
	cout << endl;


	return 0;
}


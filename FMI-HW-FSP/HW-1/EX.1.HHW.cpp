#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	unsigned num;
	cin >> num;

	if (num > 2999)
	{
		cout << "Invalid number!" << endl;
		return 1;
	}

	unsigned thousands = num / 100;
	unsigned hundreds = num / 10;
	unsigned units = num % 10;
	
	if (thousands != 0 )
	{
		switch (thousands)
		{
		case 1:
			cout << "M";
		case 2:
			cout << "MM";
		case 3:
			cout << "MMM";
		}

		switch (hundreds)
		{
		case 1:
			cout << "C";
		case 2:
			cout << "CC";
		case 3:
			cout << "CCC";
		case 4:
			cout << "CD";
		case 5:
			cout << "D";
		case 6:
			cout << "DC";
		case 7:
			cout << "DCC";
		case 8:
			cout << "DCCC";
		case 9:
			cout << "CM";
		}

		switch (units)
		{
		case 1:
			cout << "I";
		case 2:
			cout << "II";
		case 3:
			cout << "III";
		case 4:
			cout << "IV";
		case 5:
			cout << "V";
		case 6:
			cout << "VI";
		case 7:
			cout << "VII";
		case 8:
			cout << "VIII";
		case 9:
			cout << "IX";
		}

	}

	return 0;
}
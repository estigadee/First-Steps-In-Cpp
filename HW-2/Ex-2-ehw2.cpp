#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	unsigned card_id;
	cout << "Enter your card ID: ";
	cin >> card_id;

	unsigned card_version = card_id / 100000000;
	unsigned owner_spec = (card_id % 10000000) / 1000000;
	unsigned owner_id = (card_id % 1000000) / 10;


	if (card_id < 0 || card_version == 0 || card_version > 9 || card_version < 1 || owner_spec > 8 || owner_spec == 7 || owner_id == 0)
	{
		cout << "Invalid card number!" << endl;

		return 1;
	}
	

	unsigned personal_info = (card_id / 10000000) % 10;

	unsigned mask = (1 << 0);

	unsigned gender = personal_info & mask;
	unsigned hair = personal_info & (mask << 1);
	unsigned eyes = personal_info & (mask << 2);

	if (personal_info > 8)
	{
		cout << "The card is not original!" << endl;
		return 1;
	}
	else
	{
		gender % 2 == 0 ? cout << "Women" : cout << "Men";
		cout << " with ";
		hair - 2 == 0 ? cout << "dark hair" : cout << "light hair";
		cout << " and ";
		eyes - 4 == 0 ? cout << "dark eyes" : cout << "light eyes";

	}
	cout << endl;


	unsigned sum_even = (personal_info + (card_id / 100000) % 10 + (card_id / 1000) % 10 + (card_id / 10) % 10);
	unsigned sum_odd = (card_id / 100000000) + (card_id / 1000000) % 10 + (card_id / 10000) % 10 + (card_id / 100) % 10 + card_id % 10;

	unsigned sum_prod = sum_odd*sum_even;


	if ((hair - 2 == 0) && (eyes - 4 == 0))
	{
		sum_prod = sum_prod | 0xCAFE;
	}
	else
		if ((hair - 2 != 0) && (eyes - 4 != 0))
		{
			sum_prod = sum_prod | 0xBABE;
		}
		else
		{
			sum_prod = sum_prod | 0xC001;
		}


	if (gender % 2 == 0)
	{
		sum_prod = sum_prod ^ 0xFACE;
	}
	else
	{
		sum_prod = sum_prod ^ 0xC0DE;
	}

	sum_prod = (sum_prod >> 12);

	if (sum_prod > 10)
	{
		sum_prod = sum_prod % 10;
	}


	unsigned check_digit = card_id % 10;

	if (check_digit == sum_prod)
	{
		cout << "Authentic!" << endl;
	}
	else
	{
		cout << "Imitative!" << endl;
	}

	return 0;
}
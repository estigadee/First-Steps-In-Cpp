#include "stdafx.h"
#include <iostream>
#include <cmath>

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

	int saved_nums = 0;
	int id_num = 0;
	int positions = n;

	while (n > 0)
	{
		int i = 0;
		cin >> i;
		if (i / 100000000 < 1)
		{
			cout << "Invalid card number!" << endl;

			return 1;
		}

		if (i > id_num)
		{
			saved_nums = saved_nums * 10 + 1;
		}
		else
		{
			saved_nums = saved_nums * 10;
		}
		id_num = i;

		n--;
	}
	cout << saved_nums << endl;

	int check_num = 0;
	int cnt_one = 1;
	int all_saved_nums = saved_nums;

	while (saved_nums > 0)
	{
		check_num = saved_nums % 10;

		if (check_num == 1)
		{
			cnt_one++;
		}

		saved_nums = saved_nums / 10;
	}

	int middle_one_pos = 0;

	if (cnt_one % 2 == 0)
	{
		middle_one_pos = cnt_one / 2;
	}
	else
	{
		middle_one_pos = (cnt_one - 1) / 2;
	}


	int steps_to_middle = pow(10, positions - middle_one_pos + 1);


	int right_side = all_saved_nums % steps_to_middle;
	int left_side = all_saved_nums / steps_to_middle;

	int cnt_zero_left = 0;
	int zero_check = 0;

	while (left_side > 0)
	{
		zero_check = left_side % 10;

		if (zero_check == 0)
		{
			cnt_zero_left++;
		}

		left_side /= 10;
	}

	zero_check = 0;
	int cnt_zero_right = 0;

	while (right_side > 0)
	{
		zero_check = right_side % 10;

		if (zero_check == 0)
		{
			cnt_zero_right++;
		}

		right_side /= 10;
	}

	if (cnt_zero_left > cnt_zero_right)
	{
		cout << "Left side: " << cnt_zero_left << endl;
	}
	if (cnt_zero_right > cnt_zero_left)
	{
		cout << "Right side: " << cnt_zero_right << endl;
	}
	if (cnt_zero_left == cnt_zero_right)
	{
		cout << "Both sides: " << cnt_zero_right << endl;
	}


	return 0;
}





//int saved_nums = 0;
//int id_num = 0;
//int positions = n;
//
//int mask = (1 << 0);
//
//while (n > 0)
//{
//
//	int i = 0;
//	cin >> i;
//	int cnt = 0;
//
//	if (i > id_num)
//	{
//		saved_nums = (saved_nums << 1) | mask;
//		cnt++;
//	}
//	else
//	{
//		saved_nums = (saved_nums << 1);
//	}
//	id_num = i;
//
//	n--;
//}
//cout << saved_nums << endl;
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool is_prime(int n)
{
	if (n == 0 || n == 1)
	{
		return false;
	}

	int limit = sqrt(n);

	for (int i = 2; i <= limit; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int prime_lands_counter(int land[], int lenght)
{
	int prime_counter = 0;
	for (int i = 0; i < lenght; i++)
	{
		int cnt = 0;
		while (land[i] > 0)
		{
			cnt++;
			i++;
		}
		if (is_prime(cnt))
		{
			prime_counter++;
		}
	}

	return prime_counter;
}
void prime_lands(int land[], int lenght)
{
	bool prime_lands_exist = false;
	for (int i = 0; i < lenght; i++)
	{
		int cnt = 0;
		while (land[i] > 0)
		{
			cnt++;
			i++;
		}
		if (is_prime(cnt))
		{
			cout << cnt << " ";
			prime_lands_exist = true;
		}
	}

	if (!prime_lands_exist)
	{
		cout << 0;
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));
	int my_land[12] = { 1,1,1,1,1,1,0,0,1,0,1,1 };

	int land[10000];
	int lenght = 0;

	cin >> lenght;

	if (lenght == 0)
	{
		print_arr(my_land, 12);

		lenght = 12;

		for (int i = 0; i < lenght; i++)
		{
			land[i] = my_land[i];
		}
	}
	else
		if (lenght > 0)
		{
			for (int i = 0; i < lenght; i++)
			{
				cin >> land[i];
			}
		}
		else
		{
			lenght = rand() % 10000 + 10;

			for (int i = 0; i < lenght; i++)
			{
				land[i] = rand() % 100 < 50 ? 0 : 1;
			}
			print_arr(land, lenght);

		}


	int zero_cnt = 0;
	int need_land = 0;

	int one_cnt = 0;

	int index = 0;
	int help_index = 0;
	int longest = 0;


	for (int i = 0; i < lenght; i++)
	{
		if (land[i] == 1)
		{
			index = i;
			one_cnt++;

			zero_cnt = 0;
		}
		else
		{
			one_cnt = 0;
			zero_cnt++;
		}

		if (zero_cnt > 3)
		{
			need_land++;
			zero_cnt = 0;
		}

		if (longest < one_cnt)
		{
			longest = one_cnt;
			help_index = index - (longest - 1);
		}
	}

	zero_cnt = 0;
	int start_index = 0;
	int start_lenght = 0;
	bool found_one = false;

	for (int i = 0; i < lenght; i++)
	{
		if (land[i] == 1 || found_one)
		{
			found_one = true;
			start_index = i;
			start_lenght++;
		}

		if (land[i] == 0)
		{
			zero_cnt++;
		}

		if (zero_cnt > 3 && found_one)
		{
			if (start_lenght > zero_cnt)
			{
				start_lenght = start_lenght - zero_cnt;
			}
			break;
		}

	}

	cout << "Best starting position is " << (start_index - (start_lenght - 1));
	cout << " and the run lenght is " << start_lenght << " steps. ";
	cout << "Longest platform start form position " << help_index << " and has lenght of  " << longest << endl;
	cout << "There are " << prime_lands_counter(land, lenght) << " prime-lenght platforms. ";
	cout << "They are with lenght ";
	prime_lands(land, lenght);
	cout << "Mario needs " << need_land << " new platform with total lenght " << need_land << ". " << endl;

	return 0;
}

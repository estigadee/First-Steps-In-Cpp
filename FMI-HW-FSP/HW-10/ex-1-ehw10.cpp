#include <iostream>
using namespace std;

bool does_number_contain_digit(long long int num, long long int k)
{
	if (num < 10)
	{
		return num == k;
	}

	if (num % 10 == k)
	{
		return true;
	}
	else
	{
		return does_number_contain_digit(num / 10, k);
	}
}

bool does_number_has_repeated_digit(long long int num)
{
	if (num > 999999999)
	{
		return true;
	}
	if (num < 10)
	{
		return false;
	}
	if (does_number_contain_digit(num / 10, num % 10))
	{
		return true;
	}
	else
	{
		return does_number_has_repeated_digit(num / 10);
	}
}

int main()
{

	long long int next_num;
	while (true) {
		cin >> next_num;
		cout << (does_number_has_repeated_digit(next_num) ? "Yes" : "No") << endl;
	}

	return 0;
}

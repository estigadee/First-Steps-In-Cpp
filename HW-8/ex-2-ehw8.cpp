#include <iostream>
using namespace std;

typedef unsigned int uint;

bool is_pow_of_two(uint num);
void read_array(uint *arr, uint size);
uint* allocate_array(uint size);
void resize_array(uint *&arr, uint &size, uint x);
uint max_element(uint *arr, uint size);
uint max_el_index(uint *arr, uint size, uint x);
void command_P(uint *arr, uint size);
void command_E(uint *arr);
void command_A(uint *&arr, uint &size, uint x);

int main()
{
	char command;
	uint size, x = 0;
	cin >> size;

	uint *arr = allocate_array(size);

	if (arr != nullptr)
	{
		read_array(arr, size);

		do
		{
			cout << "Enter a command: ";
			cin >> command;

			if (command == 'A')
			{
				cout << "Number of soldiers: ";
				cin >> x;

				command_A(arr, size, x);
			}
			else
				if (command == 'P')
				{
					command_P(arr, size);
				}
				else
					if (command == 'E')
					{
						command_E(arr);
					}

		} while (command != 'E');
	}
	return 0;
}

bool is_pow_of_two(uint num)
{
	if (num > 1)
	{
		while (num % 2 == 0)
		{
			num = num / 2;
		}
		return (num == 1);
	}
	return false;
}

void read_array(uint *arr, uint size)
{
	for (uint i = 0; i < size; i++)
	{
		cin >> arr[i];
		if (!(is_pow_of_two(arr[i])))
		{
			i--;
		}
	}
}

uint* allocate_array(uint size)
{
	if (size < 4 || size > 1024)
	{
		return nullptr;
	}
	uint* arr = new(nothrow) uint[size]{ 0 };
	if (arr == nullptr)
	{
		return nullptr;
	}
	return arr;
}

void resize_array(uint *&arr, uint &size, uint x)
{
	size = size + x;
	uint *arr_2 = allocate_array(size);

	for (uint i = 0; i < size - x; i++)
	{
		arr_2[i] = arr[i];
	}
	command_E(arr);
	arr = arr_2;
}

uint max_element(uint *arr, uint size)
{
	uint max_el = arr[0];
	for (uint i = 0; i < size - 1; i++)
	{
		if (max_el < arr[i + 1])
		{
			max_el = arr[i + 1];
		}
	}
	return max_el;
}

uint max_el_index(uint *arr, uint size, uint element)
{
	for (uint i = 0; i < size; i++)
	{
		if (element == arr[i])
		{
			return i;
		}
	}

	return 0;
}

void command_A(uint *&arr, uint &size, uint x)
{
	resize_array(arr, size, x);

	uint max_el = 0;
	uint index = 0;

	while (x != 0)
	{
		max_el = max_element(arr, size);
		index = max_el_index(arr, size, max_el);

		if (max_el == 2)
		{
			cout << "Try again after Hoth. " << endl;
			break;
		}

		for (uint i = size - 1; i > index; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[index] = max_el / 2;
		arr[index + 1] = max_el / 2;
		x--;
	}
}

void command_P(uint *arr, uint size)
{
	cout << "[";
	for (uint i = 0; i < size; i++)
	{
		cout << arr[i];
		if (i != size - 1)
		{
			cout << ", ";
		}
	}
	cout << "]";
	cout << endl;
}

void command_E(uint *arr)
{
	if (arr != nullptr)
	{
		delete[] arr;
	}
	arr = nullptr;
}
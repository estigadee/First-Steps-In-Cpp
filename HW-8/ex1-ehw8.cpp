#include <iostream>
using namespace std;

typedef unsigned int uint;

void read_matrix(int **matrix, uint n, uint m);
void print_matrix(int **matrix, uint n, uint m);
void delete_matrix(int **matrix, uint n);
int** allocate_matrix(uint n, uint m);
int elements_sum(int **matrix, uint row, uint m);
void change_rows(int **matrix, uint m, uint row1, uint row2);

int main()
{
	uint n, m;
	cin >> n >> m;

	int ** matrix = allocate_matrix(n, m);

	if (matrix != nullptr)
	{
		read_matrix(matrix, n, m);

		for (uint i = 0; i < n - 1; i++)
		{
			int z = elements_sum(matrix, i, n);
			for (uint j = i + 1; j < n; j++)
			{
				int y = elements_sum(matrix, j, n);

				if (z > y)
				{
					change_rows(matrix, n, i, j);
				}
			}
		}
		print_matrix(matrix, n, m);
	}

	if (matrix != nullptr)
	{
		delete_matrix(matrix, n);
	}

	return 0;
}
void read_matrix(int **matrix, uint n, uint m)
{
	for (uint i = 0; i < n; i++)
	{
		for (uint j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
}
void print_matrix(int **matrix, uint n, uint m)
{
	for (uint i = 0; i < n; i++)
	{
		for (uint j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void delete_matrix(int **matrix, uint n)
{
	for (uint i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
int** allocate_matrix(uint n, uint m)
{
	int** matrix = new(nothrow) int*[n];
	if (matrix == nullptr)
	{
		return nullptr;
	}

	for (uint i = 0; i < n; i++) {
		matrix[i] = new(nothrow) int[m];
		if (matrix[i] == nullptr)
		{
			delete_matrix(matrix, i);
			return nullptr;
		}
	}
	return matrix;
}
int elements_sum(int **matrix, uint row, uint m)
{
	int sum = 0;
	for (uint i = 0; i < m; i++)
	{
		sum += matrix[row][i];
	}
	return sum;
}
void change_rows(int **matrix, uint m, uint row1, uint row2)
{
	for (uint i = 0; i < m; i++)
	{
		int helper = matrix[row1][i];
		matrix[row1][i] = matrix[row2][i];
		matrix[row2][i] = helper;
	}
}

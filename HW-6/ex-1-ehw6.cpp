#include "stdafx.h"
#include <iostream>
using namespace std;

void read_matrix(int matrix[][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

int main()
{
	int matrix[100][100];
	int n, m;
	cin >> n >> m;

	read_matrix(matrix, n, m);


	int prod_row = 1;
	int prod_col = 1;
	int temp_row = 0;

	while (temp_row < n)
	{

		for (int col = 0; col < m - 1; col++)
		{
			prod_row *= matrix[temp_row][col];
		}

		for (int col = 0; col < m - 1; col++)
		{
			for (int row = 0; row < n - 1; row++)
			{
				prod_col *= matrix[row][col];
			}
			if (prod_row == prod_col)
			{
				cout << "(" << temp_row << ", " << col << ")";
			}
			cout << endl;

			prod_col = 1;
		}

		temp_row++;
		prod_row = 1;
	}

	return 0;
}


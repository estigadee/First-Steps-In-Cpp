#include "stdafx.h"
#include <iostream>
using namespace std;

typedef unsigned int uint;

bool is_any_free_position(char matrix[][10], uint n);

bool is_free_position(char matrix[][10], uint n, uint pos_x, uint pos_y);

bool is_winner_main_diagonal(char matrix[][10], uint n, char symbol);

bool is_winner_secondary_diagonal(char matrix[][10], uint n, char symbol);

bool is_winner_col(char matrix[][10], uint n, char symbol);

bool is_winner_row(char matrix[][10], uint n, char symbol);

bool is_winner(char matrix[][10], uint n, char symbol);

void print_matrix(char matrix[][10], uint n, uint pos_x, uint pos_y, char syambol);

int gen_random_pos(uint n);

int main()
{
	char matrix[10][10] = { ' ', };

	uint n = 0;
	uint pos_x = 0;
	uint pos_y = 0;
	char first_symbol;
	char second_symbol;
	char symbol;
	char game;

	cin >> n;

	if (n < 3 || n > 9)
	{
		return 1;
	}

	cout << "Press \"C\" if you want to play vs computer or press \"P\" if you want to play vs another player: ";
	cin >> game;

	cout << "Choose \"X\" or \"O\" : ";
	cin >> first_symbol;

	/*if (first_symbol != 'X' || first_symbol != 'O')
	{
	return 1;
	}*/

	if (first_symbol == 'X')
	{
		second_symbol = 'O';
	}
	else
	{
		second_symbol = 'X';
	}

	uint turn = 0;
	bool equal_result = false;

	if (game == 'P')
	{

		while (is_any_free_position(matrix, n))
		{
			if (turn % 2 == 0)
			{
				symbol = first_symbol;
			}
			else
			{
				symbol = second_symbol;
			}
			turn++;

			cin >> pos_x >> pos_y;

			if (pos_x > n || pos_x < 1 || pos_y > n || pos_y < 1)
			{
				return 1;
			}


			if (is_free_position(matrix, n, pos_x, pos_y))
			{
				matrix[pos_x][pos_y] = symbol;
				print_matrix(matrix, n, pos_x, pos_y, symbol);
			}
			else
			{
				return 1;
			}

			equal_result = false;

			if (is_winner(matrix, n, symbol))
			{
				if (symbol == first_symbol)
				{
					cout << "First player is winner!";
					break;
				}
				else
					if (symbol == second_symbol)
					{
						cout << "Second player is winner!";
						break;
					}
			}
			else
			{
				equal_result = true;
			}
		}

		if (equal_result)
		{
			cout << "Standoff!" << endl;
		}
	}
	else
	{
		while (is_any_free_position(matrix, n))
		{
			if (turn % 2 == 0)
			{
				symbol = first_symbol;
				pos_x = gen_random_pos(n);
				pos_y = gen_random_pos(n);
			}
			else
			{
				symbol = second_symbol;
				cin >> pos_x >> pos_y;
			}
			turn++;

			if (pos_x > n || pos_x < 1 || pos_y > n || pos_y < 1)
			{
				return 1;
			}


			if (is_free_position(matrix, n, pos_x, pos_y))
			{
				matrix[pos_x][pos_y] = symbol;
				print_matrix(matrix, n, pos_x, pos_y, symbol);
			}
			else
			{
				turn--;
			}

			equal_result = false;

			if (is_winner(matrix, n, symbol))
			{
				if (symbol == first_symbol)
				{
					cout << "First player is winner!";
					break;
				}
				else
					if (symbol == second_symbol)
					{
						cout << "Second player is winner!";
						break;
					}
			}
			else
			{
				equal_result = true;
			}
		}
	}
	return 0;
}

bool is_any_free_position(char matrix[][10], uint n)
{
	for (uint row = 1; row <= n; row++)
	{
		for (uint col = 1; col <= n; col++)
		{
			if (matrix[row][col] != 'X' && matrix[row][col] != 'O')
			{
				return true;
			}
		}
	}
	return false;
}

bool is_free_position(char matrix[][10], uint n, uint pos_x, uint pos_y)
{
	if (pos_x > n || pos_x < 1 || pos_y > n || pos_y < 1)
	{
		return false;
	}

	return matrix[pos_x][pos_y] != 'X' && matrix[pos_x][pos_y] != 'O';

}

bool is_winner_main_diagonal(char matrix[][10], uint n, char symbol)
{
	bool win = true;

	for (uint row = 1; row <= n; row++)
	{
		if (matrix[row][row] != symbol)
		{
			win = false;
			break;
		}
	}

	return win;
}

bool is_winner_secondary_diagonal(char matrix[][10], uint n, char symbol)
{
	bool win = true;
	for (uint row = 1; row <= n; row++)
	{
		win = false;
		if (matrix[row][n + 1 - row] != symbol)
		{
			win = false;
			break;
		}
	}
	return win;
}

bool is_winner_col(char matrix[][10], uint n, char symbol)
{
	for (uint row = 1; row <= n; row++)
	{
		bool win = true;

		for (uint col = 1; col <= n; col++)
		{
			if (matrix[col][row] != symbol)
			{
				win = false;
				break;
			}
		}
		if (win)
		{
			return true;
		}
	}
	return false;
}

bool is_winner_row(char matrix[][10], uint n, char symbol)
{
	for (uint row = 1; row <= n; row++)
	{
		bool win = true;

		for (uint col = 1; col <= n; col++)
		{
			if (matrix[row][col] != symbol)
			{
				win = false;
				break;
			}
		}
		if (win)
		{
			return true;
		}
	}

	return false;
}

bool is_winner(char matrix[][10], uint n, char symbol)
{
	return is_winner_main_diagonal(matrix, n, symbol) ||
		is_winner_secondary_diagonal(matrix, n, symbol) ||
		is_winner_col(matrix, n, symbol) ||
		is_winner_row(matrix, n, symbol);
}

void print_matrix(char matrix[][10], uint n, uint pos_x, uint pos_y, char symbol)
{
	for (uint row = 1; row <= n; row++)
	{
		for (int col = 1; col <= n; col++)
		{
			cout << "[" << matrix[row][col] << "]" << " ";
		}
		cout << endl;
	}
	cout << endl;

}

int gen_random_pos(uint n)
{
	return rand() % n + 1;
}
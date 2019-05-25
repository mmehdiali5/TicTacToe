#include<iostream>
using namespace std;
#include "Presentation.h"
#include "business.h"

void ticTacToeApp()
{
	char ticTacToe[3][3][3] = { {'1','2','3','4','5','6','7','8','9'},{'1','2','3','4','5','6','7','8','9'} ,{'1','2','3','4','5','6','7','8','9'} };
	char symbol1, symbol2;
	bool input = false;
	do
	{
		cout << "Enter symbol of Player 1: ";
		cin >> symbol1;
		cout << "Enter symbol of Player 2: ";
		cin >> symbol2;
		if (symbol1 != symbol2)
		{
			input = true;
	    }
		else if (symbol1 == symbol2)
		{
			cout << "Enter Different symbol\n";
		}
	}while (!input);
	int winner=playTicTacToe(ticTacToe,symbol1,symbol2);
	displayTicTacToe(ticTacToe);
	if (winner == symbol1)
	{
		cout << "\nPlayer 1 wins!";
	}
	else if (winner == symbol2)
	{
		cout << "\nPlayer 2 wins!";
	}
	else if (winner == 0)
	{
		cout << "\nMatch Is Drawn";
	}
}

void displayTicTacToe(char a[][3][3])
{
	for (int j = 0; j < 3; j = j + 1)
	{
		for (int i = 0; i < 3; i = i + 1)
		{
			for (int k = 0; k < 3; k = k + 1)
			{
				cout << a[i][j][k]<<"  ";
			}
			cout << "\t";
		}
		cout << '\n';
	}
	cout << "--------" << "\t" << "--------" << "\t" << "--------" << "\t"<<"\n";
	cout << "    1   " << "\t" << "    2   " << "\t" << "    3   " << "\t"<<"\n\n";
}
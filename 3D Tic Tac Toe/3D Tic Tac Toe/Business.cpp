#include<iostream>
using namespace std;
#include "Business.h"
#include "presentation.h"

int playTicTacToe(char a[][3][3],char symbol1,char symbol2)
{
	int cell, checkValue1 = 0, checkValue2 = 0, checkValue3 = 0, checkValue3d=0,checkValueDiagnols3d=0;
	int p = 1 + rand() % 2;
	int i, j;
	int turn = 0;
	while (turn < 27)
	{
		displayTicTacToe(a);
		cout << "Enter cell player " << p << ": ";
		bool input = false;
		while (!input)
		{
			cin >> cell;
			if (cell >= 11 && cell <= 39 && cell % 10 != 0)
			{
				input = true;
		    }
			else
			{
				cout << "\nEnter Valid Cell Number";
			}
		}
		cout << "\n";
		int ten = cell / 10;
		int unit = cell % 10;
		i = (unit - 1) / 3;
		j= (unit - 1) % 3;
		if (a[ten-1][i][j] == symbol1 || a[ten-1][i][j] == symbol2)
		{
			cout << "\nYou can't choose a cell more than once\n\n";
		}
		else
		{
			if (p == 1 && a[ten - 1][i][j] != symbol2)
			{
				a[ten - 1][i][j] = symbol1;
				p = 2;
			}
			else if (p == 2 && a[ten - 1][i][j] != symbol1)
			{
				a[ten - 1][i][j] = symbol2;
				p = 1;
			}
			int rows = checkRows(a, 3, &checkValue1);
			int columns = checkColumns(a, 3, &checkValue2);
			int diagonals = checkDiagonals(a, 3, &checkValue3);
			int elements3d = check3d(a, 3, &checkValue3d, symbol1, symbol2);
			int diagonals3d = check3dDiagonals(a, 3, &checkValueDiagnols3d, symbol1, symbol2);
			if (rows)
			{
				return checkValue1;
			}
			else if (columns)
			{
				return checkValue2;
			}
			else if (diagonals)
			{
				return checkValue3;
			}
			else if (elements3d)
			{
				return checkValue3d;
			}
			else if (diagonals3d)
			{
				return checkValueDiagnols3d;
			}
			turn = turn + 1;
		}
	}
	return 0;
}


bool checkRows(char a[][3][3], int N, int*winner1)
{
	int i = 0,k=0;
	int j;
	bool win = false;
	while (!win&&k < N)
	{
		for (i = 0; i < 3; i = i + 1)
		{
			int check = a[k][i][0];
			int countWin = 0;
			for (j = 0; j < N; j = j + 1)
			{
				if (check == a[k][i][j])
				{
					countWin = countWin + 1;
				}
			}
			if (countWin == 3)
			{
				win = true;
				*winner1 = a[k][i][j - 1];
			}
		}
		k = k + 1;
	}
	if (win == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkColumns(char a[][3][3], int N, int*winner2)
{
	int j = 0,k=0;
	int i;
	bool win = false;
	while (!win&&k < N)
	{
		for (j = 0; j < 3; j = j + 1)
		{
			int check = a[k][0][j];
			int countWin = 0;
			for (i = 0; i < N; i = i + 1)
			{
				if (check == a[k][i][j])
				{
					countWin = countWin + 1;
				}
			}
			if (countWin == 3)
			{
				win = true;
				*winner2 = a[k][i-1][j];
			}
		}
		k = k + 1;
	}
	if (win == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkDiagonals(char a[][3][3], int N, int*winner3)
{
	for(int k=0;k<N;k=k+1)
	{
		if ((2 * a[k][0][0]) == (a[k][1][1] + a[k][2][2]))
	    {
		*winner3 = a[k][0][0];
		return true;
        }
	
		else if ((2 * a[k][0][2]) == (a[k][1][1] + a[k][2][0]))
	    {
		*winner3 = a[k][0][2];
		return true;
	    }
    }
	return false;
}

bool check3d(char a[][3][3], int N, int*winner4,char symbol1,char symbol2)
{
	int i = 0,j,k;
	bool win = false;
	while(i<N&&win==false)
	{
		int check = a[0][i][0];
		int countWin = 0;
		 j = 0;
		while(j<N&&win == false)
		{
			for (k = 0; k < N; k = k+ 1)
			{
				if (a[k][i][j] == check&& a[k][i][j] ==symbol1|| a[k][i][j] ==symbol2)
				{
					countWin = countWin + 1;
				}
			}
			if (countWin == 3)
			{
				*winner4 = a[k-1][i][j];
				win = true;
		    }
			j = j + 1;
		}
		i = i + 1;
	}
	if (win == true)
	{
		return true;
    }
	else
	{
		return false;
	}
}

bool check3dDiagonals(char a[][3][3], int N, int*winner5, char symbol1, char symbol2)
{
	int countWin = 0;
	for (int k = 0; k < N; k = k + 1)
	{
		if (a[k][k][k] == a[0][0][0])
		{
			countWin = countWin + 1;
		}
	}
	if (countWin == 3)
	{
		*winner5 = a[0][0][0];
		return true;
    }
	else if (a[2][0][2] == a[1][1][1] && a[2][0][2] == a[0][2][0])
	{
			*winner5 = a[2][0][2];
			return true;   
	}
	else if (a[0][0][0] == a[1][1][0] && a[1][1][0] == a[2][2][0])
	{
		*winner5 = a[0][0][0];
		return true;
	}
	else if (a[0][0][1] == a[1][1][1] && a[0][0][1] == a[2][2][1])
	{
		*winner5 = a[0][0][1];
		return true;
	}
	else if (a[0][0][2] == a[1][1][2] && a[0][0][2] == a[2][2][2])
	{
		*winner5 = a[0][0][2];
		return true;
	}
	else if (a[2][0][2] == a[1][1][2] && a[2][0][2] == a[0][2][2])
	{
		*winner5 = a[0][2][2];
		return true;
	}
	else if (a[2][0][1] == a[1][1][1] && a[1][1][1] == a[0][2][1])
	{
		*winner5 = a[0][2][1];
		return true;
	}
	else if (a[2][0][0] == a[1][1][0] && a[1][1][0] == a[0][2][0])
	{
		*winner5 = a[0][2][0];
		return true;
	}
	else
	{
		return false;
	}
}
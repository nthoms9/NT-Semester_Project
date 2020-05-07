// This is the implementation file for the grid class.

#include <iostream>
#include <windows.h>
#include <iomanip>
#include "grid.h"

using namespace std;

// Deafault values are assigned.
grid::grid()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			gridUnit[i][j].type = typeE;
			gridUnit[i][j].character = 'X';
		}
	}


}

grid::~grid() {};

void grid::display()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	cout << "\n";

	// A for loop is used to display the grid.
	for (int i = 0; i < 20; i++)
	{
		cout << setw(50);
		for (int j = 0; j < 10; j++)
		{
			if (gridUnit[i][j].type != typeE)
			{
				switch (gridUnit[i][j].type)	// A switch statement is used for the different colors of each block type.
				{
				case type1: SetConsoleTextAttribute(hConsole, 1); break;
				case type2: SetConsoleTextAttribute(hConsole, 2); break;
				case type3: SetConsoleTextAttribute(hConsole, 4); break;	
				case type4: SetConsoleTextAttribute(hConsole, 5); break;
				case type5: SetConsoleTextAttribute(hConsole, 6); break;
				case type6: SetConsoleTextAttribute(hConsole, 8); break;
				case type7: SetConsoleTextAttribute(hConsole, 11); break;
				default: SetConsoleTextAttribute(hConsole, 15);
				}
			}
				
			cout << gridUnit[i][j].character << " ";
			SetConsoleTextAttribute(hConsole, 15);
		}
		cout << endl;
	}
	cout << endl;
}

void grid::downShift(int y)
{
	for (int i = y; i > 0; i--)		//A nested for loop is used to shift the values of the grid one level.
	{
		for (int j = 0; j < 10; j++)
		{
			gridUnit[i][j].character = gridUnit[i-1][j].character;
			gridUnit[i][j].type = gridUnit[i - 1][j].type;
		}
	}
}

int grid::getTypeGrid(int i, int j)
{
	return gridUnit[i][j].type;
}

void grid::set(int x, int y, piecetype type_)
{
	gridUnit[y][x].character = 'T';
	gridUnit[y][x].type = type_;
}

void grid::reset(int x, int y)
{
	gridUnit[y][x].character = 'X';
	gridUnit[y][x].type = typeE;
}
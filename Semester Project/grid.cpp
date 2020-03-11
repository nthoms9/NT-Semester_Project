#include <iostream>
#include <windows.h>
#include "grid.h"

using namespace std;

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

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (gridUnit[i][j].type != typeE)
				SetConsoleTextAttribute(hConsole, 2);
			cout << gridUnit[i][j].character << " ";
			SetConsoleTextAttribute(hConsole, 15);
		}
		cout << endl;
	}
}

void grid::set(int x, int y)
{
	gridUnit[y][x].character = 'T';
	gridUnit[y][x].type = type1;
}

void grid::reset(int x, int y)
{
	gridUnit[y][x].character = 'X';
	gridUnit[y][x].type = typeE;
}
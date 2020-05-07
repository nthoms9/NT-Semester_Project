/*
Nick Thoms
Data Structures 2020
Due: 5/6/2020
Semester Project: Fally Blocks
Description: For my semester project I recreated the game tetris. It uses four data structures, a game manager, a grid, a block with
             children blockks for each type and a score board. 
*/

#include<iostream>
#include<iomanip>
#include"game.h"
#include"grid.h"

using namespace std;

void displayTitle();

// The main function displays the title screen then creates the object for the game.
int main()
{
	displayTitle();
	char trigger;

	cin >> trigger;

	game FallyBlocks;
	FallyBlocks.runGame();

	return 0;
}

void displayTitle()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<< setw(53) << " " << "Fally Blocks";
	cout << "\n\n" << setw(47) << " " << "Input something to start: ";
}
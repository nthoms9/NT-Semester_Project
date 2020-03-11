#include<iostream>
#include<stdlib.h>
#include"game.h"

using namespace std;

game::game() {};

game::~game() {};

void game::runGame()
{
	gameGrid.display();

	runBlock();

}

void game::runBlock()
{
	block testBlock;
	while (testBlock.getY(0) != 20 && testBlock.getY(1)  != 20 && testBlock.getY(2)  != 20 && testBlock.getY(3)  != 20)
	{
		char N;
		system("CLS");
		updatePos(testBlock);
		cin >> N;
		switch (N)
		{
		case '1': testBlock.moveL(); break;
		case '2': testBlock.moveR(); break;
		default: testBlock.drop(); break;
		}
		system("CLS");
		updatePos(testBlock);
		testBlock.drop();
	}

}

void game::updatePos(block testBlock)
{
	for (int i = 0; i < 4; i++)
	{
		gameGrid.set(testBlock.getX(i), testBlock.getY(i));
	}
	gameGrid.display();
	if (testBlock.getY(0) != 20 && testBlock.getY(1) != 20 && testBlock.getY(2) != 20 && testBlock.getY(3) != 20)
	for (int i = 0; i < 4; i++)
	{
		gameGrid.reset(testBlock.getX(i), testBlock.getY(i));
	}
}
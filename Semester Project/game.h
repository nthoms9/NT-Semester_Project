#ifndef GAME_H
#define GAME_H

#include"grid.h"
#include"block.h"

using namespace std;

class game
{

public:

	game();

	~game();

	void runGame();

	void runBlock();

	void updatePos(block);

private:
	grid gameGrid;
};

#endif
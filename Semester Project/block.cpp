#include<iostream>
#include"block.h"

using namespace std;

block::block()
{	
	Xpos[0] = 4;	Ypos[0] = 0;
	Xpos[1] = 5;	Ypos[1] = 0;
	Xpos[2] = 4;    Ypos[2] = 1;
	Xpos[3] = 5;    Ypos[3] = 1;
	
};

block::~block() {};

int block::getX(int i)
{
	return Xpos[i];
}

int block::getY(int i )
{
	return Ypos[i];
}

void block::moveR()
{
	for (int i = 0; i < 4; i++)
	{
		Xpos[i]++;
	}
}

void block::moveL()
{
	for (int i = 0; i < 4; i++)
	{
		Xpos[i]--;
	}
}

void block::drop()
{
	for (int i = 0; i < 4; i++)
	{
		Ypos[i]++;
	}
}
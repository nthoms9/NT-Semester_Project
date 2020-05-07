// This is the Implementation file for the block class.

#include<iostream>
#include"block.h"

using namespace std;

// Default values are assigned
block::block()
{	
	coord[0].Xpos = 4;	  coord[0].Ypos = 0;
	coord[1].Xpos = 5;	  coord[1].Ypos = 0;
	coord[2].Xpos = 4;    coord[2].Ypos = 1;
	coord[3].Xpos = 5;    coord[3].Ypos = 1;
	
	tracker.Xpos = 4;     tracker.Ypos = 1;

	length = 2; 
	width = 2;

	btype = type1;
};

block::~block() {};

void block::setCoord(int i, int Xpos_, int Ypos_)
{
	coord[i].Xpos = Xpos_;
	coord[i].Ypos = Ypos_;
}

void block::setTracker(int Xpos_, int Ypos_)
{
	tracker.Xpos = Xpos_;
	tracker.Ypos = Ypos_;
}

void block::setLength(int length_)
{
	length = length_;
}

void block::setWidth(int width_)
{
	width = width_;
}

void block::setType(piecetype btype_)
{
	btype = btype_;
}

int block::getX(int i)
{
	return coord[i].Xpos; 
}

int block::getY(int i )
{
	return coord[i].Ypos;
}

int block::getTracker(char axis)
{
	if (axis == 'x')
		return tracker.Xpos;
	else
		return tracker.Ypos;
}

int block::getLength()
{
	return length;
}

int block::getWidth()
{
	return width;
}

piecetype block::getType()
{
	return btype;
}

void block::moveR()
{
	// A for loop is used to shift all positions one spot to the right.
	for (int i = 0; i < 4; i++)
	{
		coord[i].Xpos++;
	}
	tracker.Xpos++;
}

void block::moveL()
{
	// A for loop is used to shift all positions one spot to the left.
	for (int i = 0; i < 4; i++)
	{
		coord[i].Xpos--;
	}
	tracker.Xpos--;
}

void block::drop()
{
	// A for loop is used to shift all positions one spot down.
	for (int i = 0; i < 4; i++)
	{
		coord[i].Ypos++;
	}
	tracker.Ypos++;
}

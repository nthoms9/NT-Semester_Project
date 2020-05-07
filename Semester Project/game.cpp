// This is the implementation file for the game class.

#include<iostream>
#include<stdlib.h>  // stdlib.h and time.h are needed for a random number generator
#include<time.h>
#include"game.h"

using namespace std;

game::game() {};

game::~game() {};

void game::runGame()
{
	srand(unsigned int(time(NULL)));

	display();

	int randType = rand() % 8 + 1;

	while (endOfGame(randType) == false) // A while loop is used for the game loop. 
	{
		runBlock(randType);
		randType = rand() % 8 + 1;
	}

	system("CLS");
	display();
}

void game::runBlock(int randType)
{
	block* p;
	
	switch (randType) // The object is created using dynamically allocated memory with a pointer.
	{
	case 1: { p = new blockType1;  break; } 
	case 2: { p = new blockType2;  break; }
	case 3: { p = new blockType3;  break; }
	case 4: { p = new blockType4;  break; }
	case 5: { p = new blockType5;  break; }
	case 6: { p = new blockType6;  break; }
	case 7: { p = new blockType7;  break; }
	default:{ p = new block; break; }
	}

	while (downCheck(p) == true) // A while loop is used for the the block loop.
	{
		char N;
		system("CLS");
		updatePos(p);	// The position is updated and displayed.
		cin >> N;
		switch (N)   // A switch statement is used to interpret user input.
		{
		case '1':
			if(leftCheck(p) == true)
				p->moveL(); 
			break;
		case '2': 
			if(rightCheck(p) == true)
				p->moveR(); 
			break;
		case '3': 
			instaDrop(p);
			break;
		case '4':
			if(rotateCheck(p) == true)
				rotate(p);
			else
			{
				while (leftCheck(p) == true && rotateCheck(p) == false)
					p->moveL();
				if(rotateCheck(p) == true )
					rotate(p);
			}

			break;
		default: break;
		}
		system("CLS");
		updatePos(p);
		for (int i = 1; i <= score.getLevel(); i++)
		{
			if (downCheck(p) == true)
				p->drop();
		}

	}
	score.updateScore(score.calculateScore(1, score.getLevel(), p->getTracker('y'))); // Score is added after the block loop exists.
	system("CLS");
	updatePos(p); //Ending position is updated to the grid.
	clearRow(p);
	
	delete p; // Object data is erased to clean up memory before a new block appears.
}

void game::updatePos(block* &p)
{
	bool continueDrop = downCheck(p);
	for (int i = 0; i < 4; i++)			// A for loop is used to update the grid for each coordinate in the block object.
	{
		gameGrid.set(p->getX(i), p->getY(i), p->getType());
	}
	display();
	if (continueDrop == true)
	{
		for (int i = 0; i < 4; i++)		// A for loop is used to reset the grid for each coordinate in the block object.
		{
			gameGrid.reset(p->getX(i), p->getY(i));
		}
	}
}

void game::instaDrop(block* &p)
{
	while (downCheck(p) == true)
	{
		p->drop();
	}
}

void game::rotate(block*& p)
{
	for (int i = 0; i < 4; i++)
	{
		// x value is on the far right of the block.
		if (p->getX(i) == p->getTracker('x') + p->getWidth() - 1)
		{
			p->setCoord(i, (p->getTracker('x') + (p->getTracker('y') - p->getY(i))), p->getTracker('y'));
		}
		// x value is on the far left of the block
		else if (p-> getX(i) == p->getTracker('x'))
		{
			p->setCoord(i, (p->getTracker('x') + (p->getTracker('y') - p->getY(i))), (p->getTracker('y') - p->getWidth() + 1));
		}
		// y value is on the top of the block
		else if (p->getY(i) == p->getTracker('y') - p->getLength() + 1)
		{
			p->setCoord(i, (p->getTracker('x') + p->getLength() - 1), (p->getTracker('y') - (p->getX(i) - p->getTracker('x'))));
		}
		// y value is on the bottom of the block.
		else if (p->getY(i) == p->getTracker('y'))
		{
			p->setCoord(i, p->getTracker('x'), (p->getTracker('y') - (p->getX(i) - p->getTracker('x'))));
		}
	}

	int z = p->getWidth();
	p->setWidth(p->getLength());
	p->setLength(z);
}

void game::clearRow(block* p)
{
	for (int i = 0; i < p->getLength(); i++)
	{
		if (fullRowCheck(p->getTracker('y')) == true)
		{
			gameGrid.downShift(p->getTracker('y') - i);
			score.updateScore(score.calculateScore(2, score.getLevel(), p->getTracker('y')));
			score.updateLines();
			score.updateLevel(score.getLines());
		}
	}
}

void game::display()// This function combines the display functions
{
	gameGrid.display();
	score.display();
	cout << "Inputs:\n1: Left\n2: Right\n3: Bottom\n4: Rotate\n5: Drop";
}

bool game::downCheck(block* p)
{
	bool adjacentBlock = false;

	for (int i = 0; i < 4; i++)
	{
		if (gameGrid.getTypeGrid(p->getY(i) + 1, p->getX(i)) != typeE) // checks for adjacent blocks.
			adjacentBlock = true;
	}

	if (p->getTracker('y') != 19 && adjacentBlock == false)
		return true;
	else
		return false;
}

bool game::rightCheck(block* p)
{
	bool adjacentBlock = false;

	for (int i = 0; i < 4; i++)
	{
		if (gameGrid.getTypeGrid(p->getY(i), p->getX(i) + 1) != typeE) //checks for adjacent blocks
			adjacentBlock = true;
	}

	if (p->getTracker('x') + p->getWidth() <= 9 && adjacentBlock == false)
		return true;
	else
		return false;
}

bool game::leftCheck(block* p)
{
	bool adjacentBlock = false;

	for (int i = 0; i < 4; i++)
	{
		if (gameGrid.getTypeGrid(p->getY(i), p->getX(i) - 1) != typeE) // checks for adjacent blocks.
			adjacentBlock = true;
	}

	if (p->getTracker('x') != 0  && adjacentBlock == false)
		return true;
	else
		return false;
}

bool game::rotateCheck(block* p) // The rotate check has two different cases one it which it will check the right and one where
                                 // it will check up.
{
	bool adjacentBlock = false;

	if (p->getLength() > p->getWidth())
	{
		for (int i = 0; i < p->getWidth(); i++)
		{
			for (int j = 1; j < p->getLength(); j++)
			{
				if (gameGrid.getTypeGrid(p->getTracker('y') - i, p->getTracker('x') + j) != typeE)
					adjacentBlock = true;
			}
		}
		if (p->getTracker('x') + p->getLength() - 1 <= 9 && adjacentBlock == false)
			return true;
		else
			return false;
	}
	else if (p->getWidth() > p->getLength())
	{
		for (int i = 0; i < p->getLength(); i++)
		{
			for (int j = 1; j < p->getWidth(); j++)
			{
				if (gameGrid.getTypeGrid(p->getTracker('y') - j, p->getTracker('x') + i) != typeE)
					adjacentBlock = true;
			}
		}
		if (adjacentBlock == false)
			return true;
		else
			return false;
	}
	else 
		return true;
}

bool game::fullRowCheck( int y)
{
	for (int i = 0; i < 10; i++)
	{
		if (gameGrid.getTypeGrid(y, i) == typeE)
			return false;
	}
	return true;
}

// The program checks to see if it can create the next block if it cannot the game loop will end.
bool game::endOfGame(int nextType)
{
	block* p;

	switch (nextType)
	{
	case 1: { p = new blockType1;  break; }
	case 2: { p = new blockType2;  break; }
	case 3: { p = new blockType3;  break; }
	case 4: { p = new blockType4;  break; }
	case 5: { p = new blockType5;  break; }
	case 6: { p = new blockType6;  break; }
	case 7: { p = new blockType7;  break; }
	default: { p = new block; break; }
	}

	for (int i = 0; i < 4; i++)
	{
		if (gameGrid.getTypeGrid(p->getY(i), p->getX(i)) != typeE)
		{
			delete p;
			return true;
		}
			
	}
	delete p;
	return false;
}

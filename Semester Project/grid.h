// This is the specification file for the grid class.

#ifndef GRID_H
#define GRID_H

#include "block.h"


using namespace std;

struct gameGrid		//Each grid coordinate stores a type and a character
{
	piecetype type;
	char character;
};

// This class describes the grid object which is the container for the block pieces of the game.
class grid
{

public:

	grid(); // Constructor

	~grid(); // Desconstructor

	// Preconditions: The object has been created.
	// Postconditions: The grid is displayed to the screen.
	void display();

	// Preconditions: The object has been created.
	// Postconditions: The piece type at a specified coordinate is returned.
	int getTypeGrid(int i, int j);

	// Preconditions: The object has been created.
	// Postconditions: Values are assigned to a specified location on the grid. This happens during the game method "updatePos".
	void set(int x, int y, piecetype type_);

	// Preconditions: The object has been created.
	// Postconditions: Values are reset to default values for a specified location. This happens during the game method "updatePos".
	void reset(int x, int y);

	// Preconditions: The object has been created.
	// Postconditions: Each coordinates is assinged the value of the coordinate above it. This happens at a specified y value and above.
	void downShift(int y);


private:
	gameGrid gridUnit[20][10];  //The grid is created as an array 
};



#endif
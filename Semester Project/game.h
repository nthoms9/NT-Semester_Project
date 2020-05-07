// This is the specification file for the game class.

#ifndef GAME_H
#define GAME_H

// All other classes are included in this one.
#include"grid.h"
#include"block.h"
	#include"blockType1.h"
	#include"blockType2.h"
	#include"blockType3.h"
	#include"blockType4.h"
	#include"blockType5.h"
	#include"blockType6.h"
	#include"blockType7.h"
#include "scoreBoard.h"

using namespace std;

// This class acts like the body of the game, it contains the game loop, the different boolean checks for movements, and 
// also ties together all of the game objects.
class game
{

public:

	game(); // constructor

	~game(); // deconstructor

	// Preconditions: The game object has been created.
	// Postconditions: The game loop is executed.
	void runGame();

	// Preconditions: The game object has been created and the flow of control has entered the game loop, and the game can continue.
	// Postconditions: A block object is created and the block loop is executed while the space below the object is clear.
	//                 Then the block is deleted. The gameGrid object is updated when the block moves and stores the final position
	//                 of the block when the block loop exits.
	void runBlock(int);

	// Preconditions: The game object has been created and an block object has been created.
	// Postconditions: The grid object udpdates the postion of the block object, displays the result then restets the grid coordinates
	//                  to default values unless it is the end of the block loop.
	void updatePos(block* &);

	// Preconditions: The game object has been created and an block object has been created.
	// Postconditions: The block is dropped until it reaches the nearest surface.
	void instaDrop(block* &);

	// Preconditions: The game object has been created and an block object has been created.
	// Postconditions: The block is rotated one position in a clockwise direction.
	void rotate(block* &);

	// Preconditions: The game object has been created and an block object has been created.
	// Postconditions: The clearRowCheck is executed and if it returns true the grid method downshift is called and changes are made
	//                 to the score board.
	void clearRow(block*);
	// Preconditions: The game object has been created.
	// Postconditions: The grid and the score board are displayed to the screen.
	void display();

	// Preconditions: The game object has been created and an block object has been created.
	// Postconditions: A bool value is returned true  if the check is succesfull otherwise false is returned.
	bool downCheck(block*);

	// Preconditions: The game object has been created and an block object has been created.
	// Postconditions: A bool value is returned true  if the check is succesfull otherwise false is returned.
	bool rightCheck(block*);

	// Preconditions: The game object has been created and an block object has been created.
	// Postconditions: A bool value is returned true  if the check is succesfull otherwise false is returned.
	bool leftCheck(block*);

	// Preconditions: The game object has been created and an block object has been created.
	// Postconditions: A bool value is returned true  if the check is succesfull otherwise false is returned.
	bool rotateCheck(block*);

	// Preconditions: The game object has been created and an block object has been created.
	// Postconditions: A bool value is returned true  if the check is succesfull otherwise false is returned.
	bool fullRowCheck( int y);

	// Preconditions: The game object has been created and an block object has been created.
	// Postconditions: A bool value is returned true  if the check is succesfull otherwise false is returned.
	bool endOfGame(int);


private:
	grid gameGrid;     //The grid object is created
	scoreBoard score;  //The score board object is created.
};

#endif
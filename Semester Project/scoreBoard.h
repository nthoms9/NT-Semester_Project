// This is the specification file for the score board class.

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

using namespace std;

// This class describes the score board object which keeps track of points and level
class scoreBoard
{
public:

	scoreBoard();  // Constructor 
	~scoreBoard(); // Deconstructor

	// Preconditions: The object has been created.
	// Postconditions: A value is returned for the score attribute.
	int getScore();

	// Preconditions: The object has been created.
	// Postconditions: A value is returned for the level attribute.
	int getLevel();

	// Preconditions: The object has been created.
	// Postconditions: A value is returned for the lines attribute.
	int getLines();

	// Preconditions: The object has been created.
	// Postconditions: A calculation is done to see how many points the player has earned with their turn.
	int calculateScore(int, int, int);

	// Preconditions: The object has been created and one of two scenarios is initiated.
	// Postconditions: A new value is set to the score attribut equal to the previous value plus and added amount.
	void updateScore(int);

	// Preconditions: The object has been created and requirements are met for  a level up.
	// Postconditions: A new value is set to the score attribute equal to the previous value plus an added amount.
	void updateLevel(int);

	// Preconditions: The object has been created and a line has been made.
	// Postconditions: A new value is set to the score attribute equal to the previous value plus an added amount.
	void updateLines();

	// Preconditions: The object has been created.
	// Postconditions: The score board is displayed to the screen.
	void display();

private:

	int level;
	int score;		//The score board has 3 attributes.
	int lines;

};

#endif
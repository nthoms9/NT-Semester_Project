// This is the specification file for the block class.

#ifndef BLOCK_H
#define BLOCK_H

using namespace std;

enum piecetype { type1, type2, type3, type4, type5, type6, type7, typeE };// An enum distinguishes between the different block types.

struct position
{
	int Xpos;
	int Ypos;
};
// The block class describes the block object which are the individual game pieces being moved during Fally Blocks.
class block
{

public:

	block(); //Constructor

	~block(); //Destructor

	// Preconditions: The object has been created.
	// Postconditions: A value is set for the x and y positions for a single coordinate. 
	void setCoord(int i, int Xpos_, int Ypos_);

	// Preconditions: The object has been created.
	// Postconditions: A value is set for the x and y positions for the tracker coordinate. 
	void setTracker(int Xpos_, int Ypos_);

	// Preconditions: The object has been created.
	// Postconditions: A value is set for the length attribute. 
	void setLength(int length_);

	// Preconditions: The object has been created.
	// Postconditions: A value is set for width attribute. 
	void setWidth(int width_);

	// Preconditions: The object has been created.
	// Postconditions: A value is set for the btype attribute. 
	void setType(piecetype btype_);

	// Preconditions: The object has been created.
	// Postconditions: A value is returned for the x position os a single coordinate.
	int getX(int i);

	// Preconditions: The object has been created.
	// Postconditions: A value is returned for the y position os a single coordinate.
	int getY(int i);

	// Preconditions: The object has been created.
	// Postconditions: A value is returned for either the x or y positions for the tracker coordinate. 
	int getTracker(char axis);

	// Preconditions: The object has been created.
	// Postconditions: A value is returned for the length attribute. 
	int getLength();

	// Preconditions: The object has been created.
	// Postconditions: A value is returned for the width attribute.
	int getWidth();

	// Preconditions: The object has been created.
	// Postconditions: A value is returned for the btype attribute.
	piecetype getType();

	// Preconditions: The object has been created.
	// Postconditions: 1 is added to the x position for each coordinate, moving the object to the right. 
	void moveR();

	// Preconditions: The object has been created.
	// Postconditions: 1 is subtracted from the x position for each coordinate, moving the object to the left. 
	void moveL();

	// Preconditions: The object has been created.
	// Postconditions: 1 is added to the y position for each coordinate, moving the object down.  
	void drop();

private:

	position coord[4]; // A container is made to store x and y values for 4 different coordinates.
	position tracker;  // The value for an individual coordinate called the tracker is stored seperately.
	piecetype btype;   
	int length;        // A block has attributes for length, width, and type as well.
	int width;

};


#endif

#ifndef BLOCKTYPE1_H
#define BLOCKTYPE1_H

#include "block.h"

using namespace std;

//This is a child of the block class.
class blockType1 : public block
{
public:
	blockType1()
	{
		setCoord(0, 4, 0);
		setCoord(1, 5, 0);
		setCoord(2, 4, 1);
		setCoord(3, 5, 1);

		setTracker(4, 1);

		setLength(2);
		setWidth(2);

		setType(type1);

	}

};
	
#endif
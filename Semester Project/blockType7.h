#ifndef BLOCKTYPE7_H
#define BLOCKTYPE7_H

#include "block.h"

using namespace std;

//This is a child of the block class.
class blockType7 : public block
{
public:
	blockType7()
	{
		setCoord(0, 4, 0);
		setCoord(1, 4, 1);
		setCoord(2, 4, 2);
		setCoord(3, 4, 3);

		setTracker(4, 3);

		setLength(4);
		setWidth(1);

		setType(type7);

	}

};

#endif
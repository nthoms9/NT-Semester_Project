#ifndef BLOCKTYPE2_H
#define BLOCKTYPE2_H

#include "block.h"

using namespace std;

//This is a child of the block class.
class blockType2 : public block
{
public:
	blockType2()
	{
		setCoord(0, 4, 0);
		setCoord(1, 4, 1);
		setCoord(2, 5, 1);
		setCoord(3, 5, 2);

		setTracker(4, 2);

		setLength(3);
		setWidth(2);

		setType(type2);

	}

};

#endif
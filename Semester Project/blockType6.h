#ifndef BLOCKTYPE6_H
#define BLOCKTYPE6_H

#include "block.h"

using namespace std;

//This is a child of the block class.
class blockType6 : public block
{
public:
	blockType6()
	{
		setCoord(0, 5, 0);
		setCoord(1, 5, 1);
		setCoord(2, 5, 2);
		setCoord(3, 4, 2);

		setTracker(4, 2);

		setLength(3);
		setWidth(2);

		setType(type6);

	}

};

#endif
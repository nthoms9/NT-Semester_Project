#ifndef BLOCKTYPE4_H
#define BLOCKTYPE4_H

#include "block.h"

using namespace std;

//This is a child of the block class.
class blockType4 : public block
{
public:
	blockType4()
	{
		setCoord(0, 4, 0);
		setCoord(1, 4, 1);
		setCoord(2, 5, 1);
		setCoord(3, 4, 2);

		setTracker(4, 2);

		setLength(3);
		setWidth(2);

		setType(type4);

	}

};

#endif
#ifndef BLOCKTYPE3_H
#define BLOCKTYPE3_H

#include "block.h"

using namespace std;

//This is a child of the block class.
class blockType3 : public block
{
public:
	blockType3()
	{
		setCoord(0, 5, 0);
		setCoord(1, 5, 1);
		setCoord(2, 4, 1);
		setCoord(3, 4, 2);

		setTracker(4, 2);

		setLength(3);
		setWidth(2);

		setType(type3);

	}

};

#endif
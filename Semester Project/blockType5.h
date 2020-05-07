#ifndef BLOCKTYPE5_H
#define BLOCKTYPE5_H

#include "block.h"

using namespace std;

//This is a child of the block class.
class blockType5 : public block
{
public:
	blockType5()
	{
		setCoord(0, 4, 0);
		setCoord(1, 4, 1);
		setCoord(2, 4, 2);
		setCoord(3, 5, 2);

		setTracker(4, 2);

		setLength(3);
		setWidth(2);

		setType(type5);

	}

};
#endif
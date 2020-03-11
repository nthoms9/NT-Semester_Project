#ifndef GRID_H
#define GRID_H

using namespace std;

enum piecetype { type1, type2, type3, type4, type5, type6, type7, typeE };

struct gameGrid
{
	piecetype type;
	char character;
};

class grid
{

public:

	grid();

	~grid();

	void display();

	void set(int x, int y);

	void reset(int x, int y);


private:
	gameGrid gridUnit[20][10];
};



#endif
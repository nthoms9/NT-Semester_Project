#ifndef BLOCK_H
#define BLOCK_H

using namespace std;

class block
{

public:

	block();

	~block();

	int getX(int i);

	int getY(int i);

	void moveR();

	void moveL();

	void drop();

private:

	int Xpos[4];
	int Ypos[4];
};


#endif

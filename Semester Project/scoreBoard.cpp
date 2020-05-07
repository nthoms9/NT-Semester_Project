// this is the implementation file for the score board class.

#include <iostream>
#include <iomanip>
#include "scoreBoard.h"

using namespace std;

// Default values are assigned
scoreBoard::scoreBoard() 
{
    level = 1;
    lines = 0;
    score = 0;
}

scoreBoard::~scoreBoard() {}

int scoreBoard::getScore()
{
    return score;
}

int scoreBoard::getLevel()
{
    return level;
}

int scoreBoard::getLines()
{
    return lines;
}

int scoreBoard::calculateScore(int scenario, int level, int y)
{
    switch (scenario)
    {
    case 1: return((y + 1) * level); // The score calculation is different depending on the scenario.
    case 2: return(100 * level);     // Scenario 1 is if a block hits a surface. Scenario two is if a row is cleared.
    default: return 0;
    }

}

void scoreBoard::updateScore(int points)
{
    score = score + points;
}

void scoreBoard::updateLevel(int lines)
{
    if (lines % 5 == 0)  // Level is increased every 5 lines made.
        level++;
}

void scoreBoard::updateLines()
{
    lines++;
}

void scoreBoard::display()
{
    cout << setw(56) << "Score: " << score << endl;
    cout << setw(56) << "Level: " << level << endl;
    cout << setw(56) << "Lines: " << lines << endl;
}
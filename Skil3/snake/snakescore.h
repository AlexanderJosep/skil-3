#ifndef SNAKESCORE_H
#define SNAKESCORE_H

#include <string>

using namespace std;

class SnakeScore {
public:
    SnakeScore(string name, int score, int grid);
    /**
    * Gets the name of the player
    */
    string getName();

    /**
    * Gets the score of a player
    */
    int getScore();

    /**
    * Gets the grid size the player got the score at
    */
    int getGridSize();

    /**
    * Updates the score
    */
    void setScore(int score);
private:
    string name;
    int score;
    int grid;
};

#endif // SNAKESCORE_H

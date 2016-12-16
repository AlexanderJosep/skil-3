#ifndef SNAKEGRID_H
#define SNAKEGRID_H
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "config.h"

using namespace config;

class SnakeGrid {
public:
    SnakeGrid();

    /**
    * Initializes the snake grid and sets it up. Adds the snake, candy and more.
    */
    void initialize();

    /**
    * Changes the direction of the snake to dir
    */
    void setDirection(int dir);

    /**
    * Moves the snake to the next direction and increases its size if a candy is eaten. Returns false the player won/lost and true if it
    * can continue.
    */
    bool update();

    /**
    * Pushes a lost snake to the grid, everything but the part that's off the map/loses
    */
    void pushLostSnake();

    /**
    * Checks if a player has won or not
    */
    bool hasWon();

    /**
    * Returns the grid data array (0=nothing, 1=snake part, 2=candy)
    */
    short** getGrid(); // returns the grid data

    /**
    * Gets the size of the grid
    */
    short getGridSize(); // gets the grid size

    /**
    * Cets the cell X where the snake lost
    */
    short getLostSnakeX();

    /**
    * Cets the cell Y where the snake lost
    */
    short getLostSnakeY();

    /**
    * Gets snake size which is mainly used for calculating points (snake size - 3 = points)
    */
    int getSnakeSize();

    /**
    * Sets the grid size
    */
    void setGrid(int size); // sets grid size
private:
    /**
    * Updates the snakes position and checks for collision and walking out of grid. It also checks if the snake eats a candy and increases
    * the size of the snake if it does.
    */
    bool updateSnake(int dir);

    /**
    * Pushes the snake positions to the grid
    */
    void pushSnake(); // pushes the snake onto the grid

    /**
    * Pushes the candy positions to the grid.
    */
    void pushCandy();

    /**
    * Sets a candy to a random position
    */
    void setRandomCandy();

    /**
    * Resets the grid
    */
    void resetGrid();

    short **grid;
    short gridSize;
    short candyX;
    short candyY;
    short lostSnakeX;
    short lostSnakeY;
    vector<int> snakeX;
    vector<int> snakeY;
    int direction;
    bool canUpdateDir;
};

#endif // SNAKEGRID_H

#ifndef PONGBALL_H
#define PONGBALL_H

#include <ctime>
#include "pongracket.h"
#include "config.h"

using namespace config;

class PongBall {
public:
    PongBall(int width, int height, int speedX, int windowWidth, int windowHeight);

    /**
    * Returns the x position of a pong ball
    */
    int getX();

    /**
    * Returns the y position of a pong ball
    */
    int getY();

    /**
    * Returns the width of a pong ball
    */
    int getWidth();

    /**
    * Returns the height of a pong ball
    */
    int getHeight();

    /**
    * Changes the direction of a ball when it hits a racket
    */
    void changeDirection(PongRacket *racket, bool player);

    /**
    * Updates the position of the pong ball and returns a state (0 noone got a point, 1 player got a point, 2 computer got a point)
    */
    int update();

    /**
    * Reset the ball to the middle, changes the direction depending on whether the player or the computer got a point and gets
    * a random speedX.
    */
    void reset(int status);
private:
    int x;
    int y;
    int width;
    int height;
    int speedX; // how fast the ball is moving in the x direction
    int speedY; // how fast the ball is moving in the y direction
    int windowWidth;
    int windowHeight;
};

#endif // PONGBALL_H

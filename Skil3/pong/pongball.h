#ifndef PONGBALL_H
#define PONGBALL_H

#include <ctime>
#include "pongracket.h"
#include "config.h"

using namespace config;

class PongBall {
public:
    PongBall(int width, int height, int speedX, int windowWidth, int windowHeight);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    void changeDirection(PongRacket *racket, bool player);
    int update();
    void reset(int status);
private:
    int x;
    int y;
    int width;
    int height;
    int speedX;
    int speedY;
    int windowWidth;
    int windowHeight;
};

#endif // PONGBALL_H

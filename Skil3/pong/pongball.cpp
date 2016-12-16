#include "pongball.h"
#include <stdlib.h>

static int getRanInt(int size) { // get a random int from 0-size
    return rand() % size;
}

PongBall::PongBall(int width, int height, int speedX, int windowWidth, int windowHeight) {
    this -> width = width;
    this -> height = height;
    this -> speedX = speedX;
    this -> windowWidth = windowWidth;
    this -> windowHeight = windowHeight;
    srand(time(0));
    reset(1);
}

int PongBall::getX() {
    return x;
}

int PongBall::getY() {
    return y;
}

int PongBall::getWidth() {
    return width;
}

int PongBall::getHeight() {
    return height;
}

void PongBall::changeDirection(PongRacket *racket, bool player) {
    speedX = -speedX;
    speedY = (y - racket -> getY()) / (PONG_RACKET_HEIGHT / 10) - (PONG_RACKET_HEIGHT / 20);
    speedY *= 2;
    x = player ? (racket -> getX() - width) : (racket-> getX() + width);
}

int PongBall::update() {
    x += speedX;
    y += speedY;
    if(x <= 0) {
        x = 0;
        return 1;
    }
    if(x + width >= windowWidth) {
        x = windowWidth - width;
        return 2;
    }
    if(y <= 0 || y + height >= windowHeight) {
        speedY = -speedY;
        if(y <= 0) {
            y = 0;
        }
        if(y + height >= windowHeight) {
            y = windowHeight - height;
        }
    }
    return 0;
}

void PongBall::reset(int status) {
    if(status == 1 && speedX < 0) {
        speedX = -speedX;
    }
    if(status == 2 && speedX > 0) {
        speedX = -speedX;
    }
    speedY = (getRanInt(4)) * (getRanInt(1) == 0 ? -1 : 1);
    x = windowWidth / 2 - width / 2;
    y = windowHeight / 2 - height / 2;
}

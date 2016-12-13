#include "pongball.h"

PongBall::PongBall(int width, int height, int speedX, int speedY, int windowWidth, int windowHeight) {
    this -> width = width;
    this -> height = height;
    this -> speedX = speedX;
    this -> speedY = speedY;
    this -> windowWidth = windowWidth;
    this -> windowHeight = windowHeight;
    this -> x = windowWidth / 2 - width / 2;
    this -> y = windowHeight / 2 - height / 2;
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

void PongBall::update() {
    x += speedX;
    y += speedY;
    if(x <= 0 || x + width >= windowWidth) {
        speedX = -speedX;
        if(x <= 0) {
            x = 0;
        }
        if(x + width >= windowWidth) {
            x = windowWidth - width;
        }
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
}

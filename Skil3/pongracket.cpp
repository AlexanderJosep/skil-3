#include "pongracket.h"

PongRacket::PongRacket(int width, int height, int speed, int windowWidth, int windowHeight, bool player) {
    this -> width = width;
    this -> height = height;
    this -> speed = speed;
    this -> windowWidth = windowWidth;
    this -> windowHeight = windowHeight;
    this -> x = player ? windowWidth - 2 * width : width;
    this -> y = windowHeight / 2 - height / 2;
}

bool PongRacket::updatePosition(int ballX, int ballY, int ballWidth, int ballHeight) {

    return false;
}

int PongRacket::getX() {
    return x;
}

int PongRacket::getY() {
    return y;
}

int PongRacket::getWidth() {
    return width;
}

int PongRacket::getHeight() {
    return height;
}

void PongRacket::setY(int y) {
    this -> y = y;
}

#include "pongracket.h"

PongRacket::PongRacket(int width, int height, int speed, int windowWidth, int windowHeight, bool player) {
    this -> width = width;
    this -> height = height;
    this -> speed = speed;
    this -> windowWidth = windowWidth;
    this -> windowHeight = windowHeight;
    this -> player = player;
    reset();
}

void PongRacket::reset() {
    this -> x = player ? windowWidth - 2 * width : width;
    this -> y = windowHeight / 2 - height / 2;
    this -> points = 0;
}

bool PongRacket::touchesBall(int ballX, int ballY, int ballWidth, int ballHeight) {
    int x = this -> x;
    if(!player) {
        x -= width;
    }
    return x <= ballX + ballWidth && x + width >= ballX - ballWidth && y <= ballY + ballHeight && y + height >= ballY - ballHeight;
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

int PongRacket::getPoints() {
    return points;
}

void PongRacket::setY(int y) {
    this -> y = y;
}

void PongRacket::addPoint() {
    points++;
}

 void PongRacket::update(int ballY) {
    int desiredY = ballY - height / 2;
    if(desiredY < 0) {
        desiredY = 0;
    }
    if(desiredY + height >= windowHeight) {
        desiredY = windowHeight - height;
    }
    if(desiredY - y > speed) { // go down
        y += speed;
    } else if(y - desiredY > speed) { // go up
        y -= speed;
    } else {
        y = desiredY;
    }
 }

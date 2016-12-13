#ifndef PONGRACKET_H
#define PONGRACKET_H


class PongRacket {
public:
    PongRacket(int width, int height, int speed, int windowWidth, int windowHeight, bool player);
    bool updatePosition(int ballX, int ballY, int ballWidth, int ballHeight); // return true if ball should change position
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    void setY(int y);
private:
    int width;
    int height;
    int x;
    int y;
    int speed;
    int windowWidth;
    int windowHeight;
};

#endif // PONGRACKET_H

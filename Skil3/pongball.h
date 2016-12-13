#ifndef PONGBALL_H
#define PONGBALL_H


class PongBall {
public:
    PongBall(int width, int height, int speedX, int speedY, int windowWidth, int windowHeight);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    void update();
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

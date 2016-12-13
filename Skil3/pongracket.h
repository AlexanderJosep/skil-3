#ifndef PONGRACKET_H
#define PONGRACKET_H


class PongRacket {
public:
    PongRacket(int width, int height, int speed, int windowWidth, int windowHeight, bool player);
    void reset();
    bool touchesBall(int ballX, int ballY, int ballWidth, int ballHeight); // return true if ball should change direcion
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getPoints();
    void setY(int y);
    void addPoint();
    void update(int ballY);
private:
    int x;
    int y;
    int width;
    int height;
    int points;
    int speed;
    int windowWidth;
    int windowHeight;
    bool player;
};

#endif // PONGRACKET_H

#ifndef PONGRACKET_H
#define PONGRACKET_H


class PongRacket {
public:
    PongRacket(int width, int height, int speed, int windowWidth, int windowHeight, bool player);

    /**
    * Resets the racket to the middle
    */
    void reset();

    /**
    * Checks if the racket touches the ball for it to change directions
    */
    bool touchesBall(int ballX, int ballY, int ballWidth, int ballHeight);

    /**
    * Returns the x of the racket
    */
    int getX();

    /**
    * Returns the y of the racket
    */
    int getY();

    /**
    * Returns the width of the racket
    */
    int getWidth();

    /**
    * Returns the height of the racket
    */
    int getHeight();

    /**
    * Returns the points the racket has achieved
    */
    int getPoints();

    /**
    * Sets the y position, used to force change it when controlled with mouse
    */
    void setY(int y);

    /**
    * Adds a single point to thhe racket
    */
    void addPoint();

    /**
    * Updates the racket position based on the ball y. Used for controlling computer racket.
    */
    void update(int ballY);
private:
    int x;
    int y;
    int width;
    int height;
    int points;
    int speed; // speed of the computer controlled racket
    int windowWidth;
    int windowHeight;
    bool player; // true if the racket is controlled by a player
};

#endif // PONGRACKET_H

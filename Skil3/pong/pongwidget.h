#ifndef PONGWIDGET_H
#define PONGWIDGET_H

#include <QWidget>
#include <QFont>
#include <QPointF>
#include <QFontMetrics>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QMainWindow>
#include <chrono>
#include "config.h"
#include "pongball.h"
#include "pongracket.h"

using namespace config;

class PongWidget : public QWidget {
public:
    PongWidget(PongBall *ball, PongRacket *playerRacket, PongRacket *computerRacket, QMainWindow *window, int width, int height);

    /**
    * Gets the widget ready to reset the game. Also forces a wait time of one second where the widget ignores all input.
    */
    void reset(int status);

    /**
    * Returns true if the game has started
    */
    bool hasStarted();

    /**
    * Returns true of the game does need a reset
    */
    bool doesNeedReset();

    /**
    * Sets whether the game should be reset
    */
    void setNeedsReset(bool b);
protected:
    /**
    * Paints the ping rackets, the ball, the seperator etc
    */
    virtual void paintEvent(QPaintEvent *event);
    /**
    * Sets the focus to the screen when the mouse is pressed, also starts the game if it hasn't been started.
    */
    virtual void mousePressEvent(QMouseEvent *event);
    /**
    * Tracks the player's mouse to update the player's racket
    */
    virtual void mouseMoveEvent(QMouseEvent* event);
    /**
    * Closes the game and shows the main window
    */
    virtual void closeEvent(QCloseEvent *event);
private:
    PongBall *ball;
    PongRacket *playerRacket;
    PongRacket *computerRacket;
    QMainWindow *window;
    QPainter painter;
    int width;
    int height;
    bool started;
    bool needsReset;
    long double waitTime;
    int status;
};

#endif // PONGWIDGET_H

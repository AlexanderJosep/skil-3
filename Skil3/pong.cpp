#include "pong.h"
#include "pongthread.h"
#include "pongwidget.h"
#include <iostream>

static int getRanInt(int size) { // get a random int from 0-size
    return rand() % size;
}

Pong::Pong(QMainWindow *window) {
    PongBall *ball = new PongBall(PONG_BALL_WIDTH, PONG_BALL_HEIGHT, PONG_BALL_SPEED_X, 3, PONG_WINDOW_WIDTH, PONG_WINDOW_HEIGHT);
    PongRacket* playerRacket = new PongRacket(PONG_RACKET_WIDTH, PONG_RACKET_HEIGHT, -1, PONG_WINDOW_WIDTH, PONG_WINDOW_HEIGHT, true);
    PongRacket* computerRacket;

    PongWidget *widget = new PongWidget(ball, playerRacket, window, PONG_WINDOW_WIDTH, PONG_WINDOW_HEIGHT);
    widget -> setWindowTitle(QString::fromUtf8("Pong"));
    widget -> resize(PONG_WINDOW_WIDTH, PONG_WINDOW_HEIGHT);
    QSize size = QSize(PONG_WINDOW_WIDTH, PONG_WINDOW_HEIGHT);
    widget -> setMinimumSize(size);
    widget -> setMaximumSize(size);
    widget -> setStyleSheet("background-color: black");
    widget -> show();
    widget -> setFocus();
    widget -> activateWindow();
    widget -> raise();
    PongThread *thread = new PongThread(ball, widget);
    thread -> start();
   // SnakeThread *thread = new SnakeThread(grid, widget, window);
    //thread -> start();
}

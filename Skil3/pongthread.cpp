#include "pongthread.h"
#include <iostream>

PongThread::PongThread(PongBall *ball, PongRacket *playerRacket, PongRacket *computerRacket, PongWidget *widget) {
    this -> ball = ball;
    this -> widget = widget;
    this -> playerRacket = playerRacket;
    this -> computerRacket = computerRacket;
}

void PongThread::run() {
    int status = 0;
    while(widget -> isVisible()) {
        if(!widget -> hasStarted()) {
            msleep(25);
            continue;
        }
        if(widget -> doesNeedReset()) {
            widget -> setNeedsReset(false);
            playerRacket -> reset();
            computerRacket -> reset();
            ball -> reset(1);
            msleep(PONG_SLEEP_TIME);
        }
        if(status != 0) {
            ball -> reset(status);
            if(status == 1) {
                playerRacket -> addPoint();
            } else {
                computerRacket -> addPoint();
            }
            if(playerRacket -> getPoints() >= 10 || computerRacket -> getPoints() >= 10) {
                widget -> reset(status);
                widget -> update();
                msleep(1000);
            }
            status = 0;
            continue;
        }
        status = ball -> update();
        computerRacket -> update(ball -> getY());
        if(playerRacket -> touchesBall(ball -> getX(), ball -> getY(), ball -> getWidth(), ball -> getHeight())) {
            ball -> changeDirection(playerRacket, true);
        }
        if(computerRacket -> touchesBall(ball -> getX(), ball -> getY(), ball -> getWidth(), ball -> getHeight())) {
            ball -> changeDirection(computerRacket, false);
        }
        widget -> update();
        msleep(PONG_SLEEP_TIME);
    }
}

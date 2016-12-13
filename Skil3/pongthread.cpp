#include "pongthread.h"

PongThread::PongThread(PongBall *ball, PongWidget *widget) {
    this -> ball = ball;
    this -> widget = widget;
}

void PongThread::run() {
    while(widget -> isVisible()) {
        ball -> update();
        widget -> update();
        msleep(PONG_SLEEP_TIME);
    }
}

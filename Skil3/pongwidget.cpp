#include "pongwidget.h"
#include <iostream>

PongWidget::PongWidget(PongBall *ball, PongRacket *playerRacket, QMainWindow *window, int width, int height) {
    this -> ball = ball;
    this -> playerRacket = playerRacket;
    this -> window = window;
    this -> width = width;
    this -> height = height;
    this -> mouseY = -1;
    setMouseTracking(true);
}

void PongWidget::paintEvent(QPaintEvent*) {
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int h = (height - PONG_MIDDLE_SEPARATOR_COUNT * PONG_MIDDLE_SEPARATOR_SPACE) / PONG_MIDDLE_SEPARATOR_COUNT;
    int drawHeight = PONG_MIDDLE_SEPARATOR_SPACE / 2;
    for(int i = 0; i < PONG_MIDDLE_SEPARATOR_COUNT; i++) {
        painter.fillRect(QRect(width / 2 - PONG_MIDDLE_SEPARATOR_WIDTH / 2, drawHeight, PONG_MIDDLE_SEPARATOR_WIDTH, h), QBrush(QColor(255, 255, 255, 255)));
        drawHeight += PONG_MIDDLE_SEPARATOR_SPACE + h;
    }
    painter.fillRect(QRect(ball -> getX(), ball -> getY(), ball -> getWidth(), ball -> getHeight()), QBrush(QColor(255, 255, 255, 255)));

    painter.fillRect(QRect(playerRacket -> getX(), playerRacket -> getY(), playerRacket -> getWidth(), playerRacket -> getHeight()), QBrush(QColor(255, 255, 255, 255)));

    painter.end();
}

void PongWidget::mousePressEvent(QMouseEvent*) {
    //auto dur = std::chrono::system_clock::now().time_since_epoch();
    //auto currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    //if(currentTime <= waitTime + 1000) {
    //    return;
   // }
   // if(!started) {
   //     started = true;
   //     status = "Eat the candies.";
   //     return;
   // }
    setFocus();
}

void PongWidget::mouseMoveEvent(QMouseEvent* event) {
    if(mouseY < 0) {
        mouseY = event -> globalY();
        return;
    }
    playerRacket -> setY(event -> globalY() - mouseY);
    if(playerRacket -> getY() <= 0 || playerRacket -> getY() + playerRacket -> getHeight() >= height) {
        mouseY = event -> globalY();
        if(playerRacket -> getY() <= 0) {
             playerRacket -> setY(0);
             cout << "lllll" << endl;
        } else {
             playerRacket -> setY(height - playerRacket -> getHeight());
             cout << "22222" << endl;
        }
        return;
    }
}

void PongWidget::closeEvent(QCloseEvent *event) {
    window -> show();
    event -> accept();
}

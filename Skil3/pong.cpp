#include "pong.h"
#include "pongthread.h"

Pong::Pong(QMainWindow *window) {
    window -> hide();
    PongBall *ball = new PongBall(PONG_BALL_WIDTH, PONG_BALL_HEIGHT, PONG_BALL_SPEED_X, PONG_WINDOW_WIDTH, PONG_WINDOW_HEIGHT);
    PongRacket* playerRacket = new PongRacket(PONG_RACKET_WIDTH, PONG_RACKET_HEIGHT, -1, PONG_WINDOW_WIDTH, PONG_WINDOW_HEIGHT, true);
    PongRacket* computerRacket = new PongRacket(PONG_RACKET_WIDTH, PONG_RACKET_HEIGHT, 9, PONG_WINDOW_WIDTH, PONG_WINDOW_HEIGHT, false);

    PongWidget *widget = new PongWidget(ball, playerRacket, computerRacket, window, PONG_WINDOW_WIDTH, PONG_WINDOW_HEIGHT);
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
    PongThread *thread = new PongThread(ball, playerRacket, computerRacket, widget);
    thread -> start();
}

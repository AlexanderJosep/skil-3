#include "pongwidget.h"

PongWidget::PongWidget(PongBall *ball, PongRacket *playerRacket, PongRacket *computerRacket, QMainWindow *window, int width, int height) {
    this -> ball = ball;
    this -> playerRacket = playerRacket;
    this -> computerRacket = computerRacket;
    this -> window = window;
    this -> width = width;
    this -> height = height;
    setMouseTracking(true);
    started = false;
    status = 0;
    waitTime = 0;
}

void PongWidget::reset(int status) {
    this -> status = status;
    started = false;
    needsReset = true;
    auto dur = std::chrono::system_clock::now().time_since_epoch();
    waitTime = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
}

bool PongWidget::hasStarted() {
    return started;
}

bool PongWidget::doesNeedReset() {
    return needsReset;
}

void PongWidget::setNeedsReset(bool b) {
    needsReset = b;
}

void PongWidget::paintEvent(QPaintEvent*) {
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(QColor(255, 255, 255, 255));
    QFont font(QFont("times", 20));
    painter.setFont(font);
    QFontMetrics fm(font);

    int w = fm.width(QString::fromStdString(to_string(playerRacket -> getPoints())));
    if(fm.width(QString::fromStdString(to_string(computerRacket -> getPoints()))) > w) {
        w = fm.width(QString::fromStdString(to_string(computerRacket -> getPoints())));;
    }
    painter.drawText(QPointF(width / 2 + w / 2 + 10,  fm.height() + 5), QString::fromStdString(to_string(playerRacket -> getPoints())));
    painter.drawText(QPointF(width / 2 - 1.5 * w - 10, fm.height() + 5), QString::fromStdString(to_string(computerRacket -> getPoints())));

    int h = (height - PONG_MIDDLE_SEPARATOR_COUNT * PONG_MIDDLE_SEPARATOR_SPACE) / PONG_MIDDLE_SEPARATOR_COUNT;
    int drawHeight = PONG_MIDDLE_SEPARATOR_SPACE / 2;
    for(int i = 0; i < PONG_MIDDLE_SEPARATOR_COUNT; i++) {
        painter.fillRect(QRect(width / 2 - PONG_MIDDLE_SEPARATOR_WIDTH / 2, drawHeight, PONG_MIDDLE_SEPARATOR_WIDTH, h), QBrush(QColor(255, 255, 255, 255)));
        drawHeight += PONG_MIDDLE_SEPARATOR_SPACE + h;
    }
    if(started) {
        painter.fillRect(QRect(ball -> getX(), ball -> getY(), ball -> getWidth(), ball -> getHeight()), QBrush(QColor(255, 255, 255, 255)));
    }
    painter.fillRect(QRect(playerRacket -> getX(), playerRacket -> getY(), playerRacket -> getWidth(), playerRacket -> getHeight()), QBrush(QColor(255, 255, 255, 255)));
    painter.fillRect(QRect(computerRacket -> getX(), computerRacket -> getY(), computerRacket -> getWidth(), computerRacket -> getHeight()), QBrush(QColor(255, 255, 255, 255)));

    if(!started) {
        font = QFont("times", 7);
        painter.setFont(font);
        fm = QFontMetrics(font);
        QString beginning = (status == 0 ? "" : (status == 2 ? "The computer won. " : "You won! "));
        QString start = status == 0 ? "start" : "restart";
        QString s = beginning +"Please click with your mouse to "+start+".";
        painter.fillRect(QRect(40, height / 2 - PONG_START_BAR_HEIGHT / 2, width - 80, PONG_START_BAR_HEIGHT), QBrush(QColor(255, 0, 0, 160)));
        painter.drawText(QPointF(width / 2 - fm.width(s) / 2, height / 2 - PONG_START_BAR_HEIGHT / 2 + fm.height() + 5), s);
    }
    painter.end();
}

void PongWidget::mousePressEvent(QMouseEvent*) {
    auto dur = std::chrono::system_clock::now().time_since_epoch();
    auto currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    if(currentTime <= waitTime + 1000) {
        return;
    }
    if(!started) {
        started = true;
        return;
    }
    setFocus();
}

void PongWidget::mouseMoveEvent(QMouseEvent* event) {
    playerRacket -> setY(event -> y() - playerRacket -> getHeight() / 2);
    if(playerRacket -> getY() <= 0 || playerRacket -> getY() + playerRacket -> getHeight() >= height) {
        if(playerRacket -> getY() <= 0) {
             playerRacket -> setY(0);
        } else {
             playerRacket -> setY(height - playerRacket -> getHeight());
        }
        return;
    }
}

void PongWidget::closeEvent(QCloseEvent *event) {
    window -> show();
    event -> accept();
}

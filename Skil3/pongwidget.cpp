#include "pongwidget.h"

PongWidget::PongWidget(QMainWindow *window, int width, int height) {
    this -> window = window;
    this -> width = width;
    this -> height = height;
}

void PongWidget::paintEvent(QPaintEvent*) {
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int space = 10;
    int count = 25;
    int w = 6;
    int h = (height - count * space) / count;
    int drawHeight = space / 2;
    for(int i = 0; i < count; i++) {
        painter.fillRect(QRect(width / 2 - w / 2, drawHeight, w, h), QBrush(QColor(128, 128, 255, 128)));
        drawHeight += space + h;

    }


   // painter.fillRect(QRect(j * (SNAKE_CELL_SIZE + 2) + 2, i * (SNAKE_CELL_SIZE + 2) + 2 + SNAKE_BAR_OFFSET, SNAKE_CELL_SIZE, SNAKE_CELL_SIZE), QBrush(QColor(128, 128, 255, 128)));

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

void PongWidget::closeEvent(QCloseEvent *event) {
    window -> show();
    event -> accept();
}

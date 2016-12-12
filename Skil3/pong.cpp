#include "pong.h"

Pong::Pong(QMainWindow *window) {
    PongWidget *widget = new PongWidget(window, 800, 600);
    widget -> setWindowTitle(QString::fromUtf8("Pong"));
    widget -> resize(800, 600);
    QSize size = QSize(800, 600);
    widget -> setMinimumSize(size);
    widget -> setMaximumSize(size);
    widget -> setStyleSheet("background-color: black");
    widget -> show();
    widget -> setFocus();
    widget -> activateWindow();
    widget -> raise();

   // SnakeThread *thread = new SnakeThread(grid, widget, window);
    //thread -> start();
}

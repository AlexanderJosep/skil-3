#ifndef PONGWIDGET_H
#define PONGWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QMainWindow>
#include "config.h"
#include "pongball.h"
#include "pongracket.h"

using namespace config;

class PongWidget : public QWidget {
public:
    PongWidget(PongBall *ball, PongRacket *playerRacket, QMainWindow *window, int width, int height);
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void closeEvent(QCloseEvent *event);
private:
    PongBall *ball;
    PongRacket *playerRacket;
    QMainWindow *window;
    QPainter painter;
    int width;
    int height;
    int mouseY;
};

#endif // PONGWIDGET_H

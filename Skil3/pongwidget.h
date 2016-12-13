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
    void reset(int status);
    bool hasStarted();
    bool doesNeedReset();
    void setNeedsReset(bool b);
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent* event);
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

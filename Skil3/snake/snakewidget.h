#ifndef SNAKEWIDGET_H
#define SNAKEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QRect>
#include <QPointF>
#include <QBrush>
#include <QFontMetrics>
#include <QMainWindow>
#include <QMessageBox>
#include <ctime>
#include <string>
#include <chrono>
#include "snakegrid.h"
#include "config.h"

using namespace config;

class SnakeWidget : public QWidget {
public:
    SnakeWidget(SnakeGrid *gridObject, QMainWindow *window);
    void setStatus(string status);
    void setGrid(short **grid);
    void reset();
    void setPoints(string name, int pts);
    bool hasStarted();
    bool doesNeedReset();
    void setNeedsReset(bool b);
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void closeEvent(QCloseEvent *event);
private:
    QPainter painter;
    SnakeGrid *gridObject;
    QMainWindow *window;
    short **grid;
    bool started;
    bool needsReset;
    long double waitTime;
    string status;
    int points;
    string name;
};

#endif // SNAKEWIDGET_H

#ifndef PONGWIDGET_H
#define PONGWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QMainWindow>

class PongWidget : public QWidget {
public:
    PongWidget(QMainWindow *window, int width, int height);
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void closeEvent(QCloseEvent *event);
private:
    QMainWindow *window;
    QPainter painter;
    int width;
    int height;
};

#endif // PONGWIDGET_H

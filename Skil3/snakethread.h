#ifndef SNAKETHREAD_H
#define SNAKETHREAD_H
#include <QThread>
#include "snakegrid.h"
#include "snakewidget.h"
#include "config.h"

using namespace config;

class SnakeThread : public QThread {
    Q_OBJECT

public:
    SnakeThread(SnakeGrid *grid, SnakeWidget *widget);
protected:
    void run();
private:
    SnakeGrid *grid;
    SnakeWidget *widget;
};

#endif // SNAKETHREAD_H

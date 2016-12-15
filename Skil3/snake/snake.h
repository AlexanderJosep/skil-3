#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <iostream>
#include <string>
#include <QFrame>
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QSize>
#include <QObject>
#include <QInputDialog>
#include <QLineEdit>
#include <QDir>
#include <QMainWindow>
#include "storage/storage.h"
#include "snakegrid.h"
#include "snakewidget.h"
#include "snakethread.h"
#include "config.h"

using namespace config;

class Snake {
public:
    Snake(QMainWindow *window, Storage *storage);
    int getPoints();
    short getGridSize();
private:
    SnakeGrid *grid;
};

#endif // SNAKE_H

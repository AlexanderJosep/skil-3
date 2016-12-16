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
    /**
    * Creates a new snake instance. Starts the game frame, starts the snake thread and more.
    */
    Snake(QMainWindow *window, Storage *storage);
private:
    SnakeGrid *grid;
};

#endif // SNAKE_H

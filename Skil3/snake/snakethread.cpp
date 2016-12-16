#include "snakethread.h"

SnakeThread::SnakeThread(SnakeGrid *grid, SnakeWidget *widget, string name, Storage *storage) {
    this -> grid = grid;
    this -> widget = widget;
    this -> name = name;
    this -> storage = storage;
}

void SnakeThread::run() {
    while(widget -> isVisible()) { // we don't wanna keep running if the window has closed
        if(!widget -> hasStarted()) {
            msleep(25);
            continue;
        }
        if(widget -> doesNeedReset()) {
            grid -> initialize();
            widget -> setNeedsReset(false);
            msleep(SNAKE_SLEEP_TIME);
        }
        if(!(grid -> update())) {
            int points = grid -> getSnakeSize() - 3;
            if(storage -> addSnakeScore(name, points, grid -> getGridSize())) {
               widget -> setPoints(name, points);
            }
            if(grid -> hasWon()) {
                 widget -> setStatus("You WIN! Press any key to restart.");
            } else {
                grid -> pushLostSnake();
                widget -> setStatus("You lose. Press any key to restart.");
            }
            widget -> setGrid(grid -> getGrid());
            widget -> reset();
            widget -> update();
            msleep(1000);
            continue;
        }
        widget -> setGrid(grid -> getGrid());
        widget -> update();
        msleep(SNAKE_SLEEP_TIME);
    }
}

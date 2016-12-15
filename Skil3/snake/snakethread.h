#ifndef SNAKETHREAD_H
#define SNAKETHREAD_H
#include <QThread>
#include <QMessageBox>
#include "storage/storage.h"
#include "snakegrid.h"
#include "snakewidget.h"
#include "config.h"

using namespace config;

class SnakeThread : public QThread {
    Q_OBJECT

public:
    SnakeThread(SnakeGrid *grid, SnakeWidget *widget, string name, Storage *storage);
protected:
    void run();
private:
    SnakeGrid *grid;
    SnakeWidget *widget;
    string name;
    Storage *storage;
};

#endif // SNAKETHREAD_H

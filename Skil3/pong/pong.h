#ifndef PONG_H
#define PONG_H

#include <QMainWindow>
#include <QSize>
#include <QString>
#include "pongball.h"
#include "pongracket.h"
#include "config.h"

using namespace config;

class Pong {
public:
    /**
    * Creates a new instance of Pong. It opens the frame, starts the thread and more
    */
    Pong(QMainWindow *window);
};

#endif // PONG_H

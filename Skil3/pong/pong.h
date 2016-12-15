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
    Pong(QMainWindow *window);
};

#endif // PONG_H

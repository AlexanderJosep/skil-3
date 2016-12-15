#ifndef PONGTHREAD_H
#define PONGTHREAD_H
#include <QThread>
#include "pongball.h"
#include "pongwidget.h"
#include "config.h"

using namespace config;

class PongThread : public QThread {
    Q_OBJECT

public:
    PongThread(PongBall *ball, PongRacket *playerRacket, PongRacket *computerRacket, PongWidget *widget);
private:
    PongBall *ball;
    PongWidget *widget;
    PongRacket *playerRacket;
    PongRacket *computerRacket;
protected:
    void run();
};

#endif // PONGTHREAD_H

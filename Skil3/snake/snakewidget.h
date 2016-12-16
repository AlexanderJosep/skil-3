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
    /**
    * Sets the status text label on the top frame
    */
    void setStatus(string status);

    /**
    * Updates the drawing grid
    */
    void setGrid(short **grid);

    /**
    * Gets the widget ready to reset the game
    */
    void reset();

    /**
    * Sets the updated points for displaying updated hiscores.
    */
    void setPoints(string name, int pts);

    /**
    * Check if the game has started
    */
    bool hasStarted();

    /**
    * Check if the game needs to be reset
    */
    bool doesNeedReset();

    /**
    * Sets whether the game needs to be reset or not
    */
    void setNeedsReset(bool b);
protected:
    /**
    * Paints the snake, candy and board to the frame
    */
    virtual void paintEvent(QPaintEvent *event);

    /**
    * Tracks key inputs to change direction of the snake
    */
    virtual void keyPressEvent(QKeyEvent *event);

    /**
    * Sets focus to the frame if the screen has been clicked
    */
    virtual void mousePressEvent(QMouseEvent *event);

    /**
    * Closes the frame and opens the main window
    */
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

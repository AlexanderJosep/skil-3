#include "snake.h"

Snake::Snake(QMainWindow *window) {
    window -> hide();
    bool isOk;
    short gridSize = QInputDialog::getInt(window, QObject::tr("Grid"),
                                       QObject::tr("Grid size(10-30):"), 10, 10, 30, 1, &isOk);
    if(!isOk) {
        window -> show();
        return;
    }

    grid = new SnakeGrid();
    grid -> setGrid(gridSize);
    grid -> initialize();

    SnakeWidget *widget = new SnakeWidget(grid, window);
    widget -> setWindowTitle(QString::fromUtf8("Snake"));
    widget -> resize((gridSize + 2) * (SNAKE_CELL_SIZE + 2), (gridSize + 2) * (SNAKE_CELL_SIZE + 2) + SNAKE_BAR_OFFSET);
    QSize size = QSize((gridSize + 2) * (SNAKE_CELL_SIZE + 2), (gridSize + 2) * (SNAKE_CELL_SIZE + 2) + SNAKE_BAR_OFFSET);
    widget -> setMinimumSize(size);
    widget -> setMaximumSize(size);
    widget -> setGrid(grid -> getGrid());
    widget -> show();
    widget -> setFocus();
    widget -> activateWindow();
    widget -> raise();

    SnakeThread *thread = new SnakeThread(grid, widget);
    thread -> start();
}

int Snake::getPoints() {
    return grid -> getSnakeSize() - 3;
}

short Snake::getGridSize() {
    return grid -> getGridSize();
}

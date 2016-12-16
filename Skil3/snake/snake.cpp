#include "snake.h"

#include <QApplication>

#include <QMessageBox>
#include <QInputDialog>

#include <QIcon>

Snake::Snake(QMainWindow *window, Storage *storage) {
    window -> hide();
    bool isOk;
    short gridSize = QInputDialog::getInt(window, QObject::tr("Grid"),
                                       QObject::tr("Grid size(10-30):"), 10, 10, 30, 1, &isOk);
    string name;
    if(isOk) {
         name = QInputDialog::getText(window, QObject::tr("What is your username?"),
                                      QObject::tr("Username:"), QLineEdit::Normal, "", &isOk).toStdString();
    }
    if(!isOk || name.length() == 0) {
        window -> show();
        return;
    }

    grid = new SnakeGrid();
    grid -> setGrid(gridSize);
    grid -> initialize();

    SnakeWidget *widget = new SnakeWidget(grid, window);
    widget -> setWindowIcon(QIcon("./data/icons/snake.png"));
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

    SnakeThread *thread = new SnakeThread(grid, widget, name, storage);
    thread -> start();
}

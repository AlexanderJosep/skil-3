#include "snakewidget.h"

SnakeWidget::SnakeWidget(SnakeGrid *gridObject, QMainWindow *window) {
    this -> gridObject = gridObject;
    this -> window = window;
    grid = new short*[gridObject -> getGridSize()];
    for(int i = 0; i < gridObject -> getGridSize(); i++) {
        grid[i] = new short[gridObject -> getGridSize()];
        for(int j = 0; j < gridObject -> getGridSize(); j++) {
            grid[i][j] = 0;
        }
    }
    status = SNAKE_DEFAULT_STATUS;
    started = false;
    needsReset = false;
    waitTime = 0;
    points = -1;
}

void SnakeWidget::setStatus(string status) {
    this -> status = status;
}

void SnakeWidget::setPoints(string name, int pts) {
    this -> name = name;
    this -> points = pts;
}

void SnakeWidget::reset() {
    started = false;
    needsReset = true;
    auto dur = std::chrono::system_clock::now().time_since_epoch();
    waitTime = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
}

bool SnakeWidget::hasStarted() {
    return started;
}

bool SnakeWidget::doesNeedReset() {
    return needsReset;
}

void SnakeWidget::setNeedsReset(bool b) {
    needsReset = b;
}

void SnakeWidget::setGrid(short **grid) {
    this -> grid = new short*[gridObject -> getGridSize()];
    for(int i = 0; i < gridObject -> getGridSize(); i++) {
        this -> grid[i] = new short[gridObject -> getGridSize()];
        for(int j = 0; j < gridObject -> getGridSize(); j++) {
            this -> grid[i][j] = grid[i][j];
        }
    }
}


void SnakeWidget::paintEvent(QPaintEvent*) {
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //snake text
    QFont font(QFont("times", 14));
    painter.setFont(font);
    QFontMetrics fm(font);
    painter.drawText(QPointF(((gridObject -> getGridSize() + 2) * (SNAKE_CELL_SIZE + 2)) / 2 - fm.width("Snake") / 2, SNAKE_BAR_OFFSET / 2), "Snake");
    int height = fm.height() + SNAKE_BAR_OFFSET / 2;

    //points text
    font = QFont("times", 10);
    string text = "Points: "+ to_string(gridObject -> getSnakeSize() - 3);
    painter.setFont(font);
    fm = QFontMetrics(font);
    painter.drawText(QPointF(((gridObject -> getGridSize() + 2) * (SNAKE_CELL_SIZE + 2)) / 2 - fm.width(QString::fromStdString(text)) / 2, height), QString::fromStdString(text));
    height += fm.height();

    //status text
    font = QFont("times", 8);
    painter.setFont(font);
    fm = QFontMetrics(font);
    painter.drawText(QPointF(((gridObject -> getGridSize() + 2) * (SNAKE_CELL_SIZE + 2)) / 2 - fm.width(QString::fromStdString(status)) / 2, height), QString::fromStdString(status));

    for(int i = 1; i < gridObject -> getGridSize() + 1; i++) {
        for(int j = 1; j < gridObject -> getGridSize() + 1; j++) {
            if(grid[i - 1][j - 1] == 0) {
                painter.drawRect(QRect(j * (SNAKE_CELL_SIZE + 2) + 2, i * (SNAKE_CELL_SIZE + 2) + 2 + SNAKE_BAR_OFFSET, SNAKE_CELL_SIZE, SNAKE_CELL_SIZE));
            } else if(grid[i - 1][j - 1] == 1) {
                QBrush brush = painter.brush();
                painter.setBrush(Qt::darkGreen);
                painter.drawEllipse(QPointF(j * (SNAKE_CELL_SIZE + 2) + 2 + SNAKE_CELL_SIZE / 2 , i * (SNAKE_CELL_SIZE + 2) + 2 + SNAKE_CELL_SIZE / 2 + SNAKE_BAR_OFFSET), SNAKE_CELL_SIZE / 2, SNAKE_CELL_SIZE / 2);
                painter.setBrush(brush);
            } else {
                painter.fillRect(QRect(j * (SNAKE_CELL_SIZE + 2) + 2, i * (SNAKE_CELL_SIZE + 2) + 2 + SNAKE_BAR_OFFSET, SNAKE_CELL_SIZE, SNAKE_CELL_SIZE), QBrush(QColor(128, 128, 255, 128)));
            }
        }
    }
    if(gridObject -> getLostSnakeX() >= 0 && gridObject -> getLostSnakeY() >= 0) {
        int i = gridObject -> getLostSnakeX();
        int j = gridObject -> getLostSnakeY();
        QBrush brush = painter.brush();
        painter.setBrush(Qt::red);
        painter.drawEllipse(QPointF(j * (SNAKE_CELL_SIZE + 2) + 2 + SNAKE_CELL_SIZE / 2 , i * (SNAKE_CELL_SIZE + 2) + 2 + SNAKE_CELL_SIZE / 2 + SNAKE_BAR_OFFSET), SNAKE_CELL_SIZE / 2, SNAKE_CELL_SIZE / 2);
        painter.setBrush(brush);
    }
    painter.end();
    if(points >= 0) {
        QMessageBox infoBox;
        infoBox.information(this, "New hiscore!", "Your new hiscore on "+QString::fromStdString(name)+" is "+QString::fromStdString(to_string(points))+".");
        points = -1;
    }
}

void SnakeWidget::mousePressEvent(QMouseEvent*) {
    setFocus();
}

void SnakeWidget::keyPressEvent(QKeyEvent *event){
    auto dur = std::chrono::system_clock::now().time_since_epoch();
    auto currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    if(currentTime <= waitTime + 1000) {
        return;
    }
    if(!started) {
        started = true;
        status = "Eat the candies.";
        return;
    }
    int key = event -> key();
    int dir = (key == 87 || key == 16777235) ? 0 : ((key == 65 || key == 16777234) ? 1 :
              ((key == 83 || key == 16777237) ? 2 : ((key == 68 || key == 16777236) ? 3 : -1)));
    if(dir >= 0) {
        gridObject -> setDirection(dir);
    }
}

void SnakeWidget::closeEvent(QCloseEvent *event) {
    window -> show();
    event -> accept();
}

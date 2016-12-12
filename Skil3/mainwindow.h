#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDesktopWidget>
#include "userinterface.h"
#include "snake.h"
#include "pong.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void setListType(int index); // sets the list type (persons/computers/connections)
    Ui::MainWindow *ui;
    UserInterface userInterface;
    int listType;

private slots:
    void on_comboBox_activated(int index);
    void on_listSearch_textChanged(const QString &arg1);
    void on_listFilter_textChanged(const QString &arg1);
    void on_actionSnake_triggered();
    void on_actionPong_triggered();
};

#endif // MAINWINDOW_H

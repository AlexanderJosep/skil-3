#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDesktopWidget>
#include "userinterface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    UserInterface userInterface;

public slots:
    void setListType(int index); // sets the list type (persons/computers/connections)
};

#endif // MAINWINDOW_H

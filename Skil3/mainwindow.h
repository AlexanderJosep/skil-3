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
    void setListType(int index); // sets the list type (persons/computers/connections)
    Ui::MainWindow *ui;
    UserInterface userInterface;
    int listType;

private slots:
    void on_pushButton_5_clicked();
    void on_comboBox_activated(int index);
};

#endif // MAINWINDOW_H

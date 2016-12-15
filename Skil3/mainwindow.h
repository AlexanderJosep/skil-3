#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDesktopWidget>
#include <QItemSelectionModel>
#include "userinterface.h"
#include "snake/snake.h"
#include "pong/pong.h"

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
    QStandardItemModel *tableModel;
    int listType;
private slots:
    void on_comboBox_activated(int index);
    void on_listSearch_textChanged(const QString &arg1);
    void on_listFilter_textChanged(const QString &arg1);
    void on_actionSnake_triggered();
    void on_actionPong_triggered();
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_removeButton_clicked();
    void on_tableView_clicked(const QModelIndex &index);
};

#endif // MAINWINDOW_H

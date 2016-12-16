#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDesktopWidget>
#include <QItemSelectionModel>
#include <QMediaPlaylist>
#include <QMediaPlayer>
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
    /**
    * Set which list is selected (0=persons, 1=computers, 2=connections) and updates the table view
    */
    void setListType(int index);
    Ui::MainWindow *ui;
    QMediaPlayer *music;
    QMediaPlaylist *playlist;
    UserInterface userInterface;
    QStandardItemModel *tableModel;
    int listType;
private slots:
    /**
    * Changes what list is being viewed
    */
    void on_comboBox_activated(int index);

    /**
    * Updates the search results
    */
    void on_listSearch_textChanged(const QString &arg1);

    /**
    * Updated filter results
    */
    void on_listFilter_textChanged(const QString &arg1);

    /**
    * Starts the game snake when the snake menu is triggered
    */
    void on_actionSnake_triggered();

    /**
    * Starts the game pong when the pong menu is triggered
    */
    void on_actionPong_triggered();

    /**
    * Start a dialog to add a entity
    */
    void on_addButton_clicked();

    /**
    * Start a dialog to edit a entity
    */
    void on_editButton_clicked();

    /**
    * Removes a entity from the list after the are you sure has been accepted.
    */
    void on_removeButton_clicked();

    /**
    * Enables view, edit and remove depending on which type is selected when the table view is clicked
    */
    void on_tableView_clicked(const QModelIndex &index);

    /**
    * Opens the view entity frame when the buttom is clicked.
    */
    void on_viewButton_clicked();

    /**
    * Opens the snake hiscore frame
    */
    void on_actionSnake_2_triggered();

    /**
    * Starts playing the music playlist
    */
    void on_actionPlay_triggered();

    /**
    * Pauses the music that is playing
    */
    void on_actionPause_triggered();

    /**
    * Starts the next song in the playlist
    */
    void on_actionNext_triggered();

    /**
    * Starts the previous song in the playlist
    */
    void on_actionBack_triggered();
};

#endif // MAINWINDOW_H

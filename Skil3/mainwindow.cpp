#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userinterface.h"

#include "addwindow.h"
#include "editwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui -> setupUi(this);
    setListType(0);
    ui -> tableView -> setSelectionMode(QAbstractItemView::SingleSelection);
    ui -> tableView -> horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.4);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setListType(int index) {
    listType = index;
    ui -> tableView -> setModel(userInterface.getTableModel(userInterface.getSearchResults(ui -> listSearch -> text().toStdString(), ui -> listFilter -> text().toStdString(), listType), listType, this));
}

void MainWindow::on_comboBox_activated(int index){
        setListType(index);
}

void MainWindow::on_listSearch_textChanged(const QString &arg1) {
    ui -> tableView -> setModel(userInterface.getTableModel(userInterface.getSearchResults(arg1.toStdString(), ui -> listFilter -> text().toStdString(), listType), listType, this));
}

void MainWindow::on_listFilter_textChanged(const QString &arg1) {
    ui -> tableView -> setModel(userInterface.getTableModel(userInterface.getSearchResults(ui -> listSearch -> text().toStdString(), arg1.toStdString(), listType), listType, this));
}

void MainWindow::on_actionSnake_triggered() {
    Snake snake = Snake(this);
    // add hiscores to this bitch :)
}

void MainWindow::on_actionPong_triggered() {
    Pong pong = Pong(this);
}

void MainWindow::on_addButton_clicked() {
    this->hide();
    AddWindow addWindow;
    addWindow.exec();
    this->show();
}

void MainWindow::on_editButton_clicked()
{
    this->hide();
    EditWindow a;
    a.exec();
    this->show();
}

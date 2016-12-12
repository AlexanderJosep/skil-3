#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userinterface.h"

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
    ui -> tableView -> setModel(userInterface.getTableModel(userInterface.getEntities(index), index, this));\
    listType = index;
}


void MainWindow::on_pushButton_5_clicked() {
    // plus 3 because it's a search so we can do -3 when we want to get the real type
    ui -> tableView -> setModel(userInterface.getTableModel(userInterface.getSearchResults("", listType), listType, this));
}

void MainWindow::on_comboBox_activated(int index){
        setListType(index);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userinterface.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui -> setupUi(this);
    UserInterface userInterface = UserInterface();
    ui -> tableViewPersons -> setModel(userInterface.getPersonTableModel(0, this));
    ui -> tableViewPersons -> setSelectionMode(QAbstractItemView::SingleSelection);
}

MainWindow::~MainWindow() {
    delete ui;
}


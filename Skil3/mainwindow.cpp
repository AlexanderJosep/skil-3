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

    connect(ui -> comboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(setListType(int)));

    resize(QDesktopWidget().availableGeometry(this).size() * 0.4);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setListType(int index) {
    ui -> tableView -> setModel(userInterface.getTableModel(index, 0, this));
}


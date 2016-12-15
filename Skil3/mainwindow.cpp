#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userinterface.h"
#include "entity/person/addpersondialog.h"

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
    tableModel = userInterface.getTableModel(userInterface.getSearchResults(ui -> listSearch -> text().toStdString(), ui -> listFilter -> text().toStdString(), listType), listType, this);
    ui -> tableView -> setModel(tableModel);
}

void MainWindow::on_comboBox_activated(int index){
    setListType(index);
}

void MainWindow::on_listSearch_textChanged(const QString &arg1) {
    tableModel = userInterface.getTableModel(userInterface.getSearchResults(arg1.toStdString(), ui -> listFilter -> text().toStdString(), listType), listType, this);
    ui -> tableView -> setModel(tableModel);
}

void MainWindow::on_listFilter_textChanged(const QString &arg1) {
    tableModel = userInterface.getTableModel(userInterface.getSearchResults(ui -> listSearch -> text().toStdString(), arg1.toStdString(), listType), listType, this);
    ui -> tableView -> setModel(tableModel);
}

void MainWindow::on_actionSnake_triggered() {
    Snake snake = Snake(this);
    // add hiscores to this bitch :)
}

void MainWindow::on_actionPong_triggered() {
    Pong pong = Pong(this);
}

void MainWindow::on_addButton_clicked() {
    this -> hide();
    AddPersonDialog a;
    a.exec();
    this -> show();
}

void MainWindow::on_editButton_clicked() {
   // this -> hide();
    //EditWindow a;
   // a.exec();
  //  this -> show();
}

void MainWindow::on_removeButton_clicked() {
    QItemSelectionModel *item = ui -> tableView -> selectionModel();
    Entity *entity;
    QString name;
    if(listType == PERSON) {
        name = item -> selectedRows(0).value(0).data().toString();
        short gender = item -> selectedRows(1).value(0).data().toString() == "Male" ? 0 : 1;
        short birthYear = item -> selectedRows(2).value(0).data().toInt();
        short deathYear = item -> selectedRows(3).value(0).data().toString() == "Not dead" ? -1 : item -> selectedRows(3).value(0).data().toInt();
        entity = new Person(name.toStdString(), gender, birthYear, deathYear);
    } else if(listType == COMPUTER) {
        name = item -> selectedRows(0).value(0).data().toString();
        short type = 0;
        string machineType = item -> selectedRows(1).value(0).data().toString().toStdString();
        for(int i = 1; i < NUMBER_OF_MACHINES_TYPES; i++) { // no need to check for the first index
            if(machineType == MACHINE_TYPES[i]) {
                type = i;
                break;
            }
        }
        short yearBuilt = item -> selectedRows(2).value(0).data().toString() == "Not built" ? -1 : item -> selectedRows(2).value(0).data().toInt();
        cout << yearBuilt << endl;
        entity = new Computer(name.toStdString(), yearBuilt, type);
    } else {
        entity = userInterface.getConnection(item -> selectedRows(0).value(0).data().toString().toStdString(), item -> selectedRows(1).value(0).data().toString().toStdString());

    }
    if(userInterface.removeEntity(this, entity, name, listType)) {
        tableModel -> removeRow(item -> currentIndex().row(), QModelIndex());
    }
}

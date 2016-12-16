#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userinterface.h"
#include "snake/snakehiscoresdialog.h"
#include "entity/person/viewpersondialog.h"
#include "entity/computer/viewcomputerdialog.h"
#include "entity/person/addpersondialog.h"
#include "entity/computer/addcomputerdialog.h"
#include "entity/connection/addconnectiondialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui -> setupUi(this);
    setListType(0);
    ui -> tableView -> setSelectionMode(QAbstractItemView::SingleSelection);
    ui -> tableView -> horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.50);

    QPixmap pixmap(QPixmap("./icons/info.png").scaled(25, 25, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui -> viewButton -> setIcon(QIcon(pixmap));
    ui -> viewButton -> setIconSize(pixmap.rect().size());

    pixmap = QPixmap(QPixmap("./icons/add.png").scaled(25, 25, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui -> addButton -> setIcon(QIcon(pixmap));
    ui -> addButton -> setIconSize(pixmap.rect().size());

    pixmap = QPixmap(QPixmap("./icons/edit.png").scaled(25, 25, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui -> editButton -> setIcon(QIcon(pixmap));
    ui -> editButton -> setIconSize(pixmap.rect().size());

    pixmap = QPixmap(QPixmap("./icons/remove.png").scaled(25, 25, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui -> removeButton -> setIcon(QIcon(pixmap));
    ui -> removeButton -> setIconSize(pixmap.rect().size());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setListType(int index) {
    listType = index;
    tableModel = userInterface.getTableModel(userInterface.getSearchResults(ui -> listSearch -> text().toStdString(), ui -> listFilter -> text().toStdString(), listType), listType);
    ui -> tableView -> setModel(tableModel);
    ui -> editButton -> setEnabled(false);
    ui -> viewButton -> setEnabled(false);
    ui -> removeButton -> setEnabled(false);
}

void MainWindow::on_comboBox_activated(int index){
    setListType(index);
}

void MainWindow::on_listSearch_textChanged(const QString &arg1) {
    tableModel = userInterface.getTableModel(userInterface.getSearchResults(arg1.toStdString(), ui -> listFilter -> text().toStdString(), listType), listType);
    ui -> tableView -> setModel(tableModel);
}

void MainWindow::on_listFilter_textChanged(const QString &arg1) {
    tableModel = userInterface.getTableModel(userInterface.getSearchResults(ui -> listSearch -> text().toStdString(), arg1.toStdString(), listType), listType);
    ui -> tableView -> setModel(tableModel);
}

void MainWindow::on_actionSnake_triggered() {
    Snake(this, userInterface.getEntityManager() -> getStorage());
}

void MainWindow::on_actionPong_triggered() {
    Pong(this);
}

void MainWindow::on_addButton_clicked() {
    this -> hide();
    if(listType == PERSON) {
        AddPersonDialog a;
        a.setEntityManager(userInterface.getEntityManager());
        a.exec();
    } else if(listType == COMPUTER) {
        AddComputerDialog a;
        a.setEntityManager(userInterface.getEntityManager());
        a.exec();
    } else {
        AddConnectionDialog a;
        a.setEntityManager(userInterface.getEntityManager());
        a.exec();
    }
    tableModel = userInterface.getTableModel(userInterface.getSearchResults(ui -> listSearch -> text().toStdString(), ui -> listFilter -> text().toStdString(), listType), listType);
    ui -> tableView -> setModel(tableModel);
    ui -> editButton -> setEnabled(false);
    ui -> viewButton -> setEnabled(false);
    ui -> removeButton -> setEnabled(false);
    this -> show();
}

void MainWindow::on_editButton_clicked() {
    this -> hide();
    QItemSelectionModel *item = ui -> tableView -> selectionModel();
    if(listType == PERSON) {
        AddPersonDialog a;
        a.setEntityManager(userInterface.getEntityManager());
        QString name = item -> selectedRows(0).value(0).data().toString();
        short gender = item -> selectedRows(1).value(0).data().toString() == "Male" ? 0 : 1;
        short birthYear = item -> selectedRows(2).value(0).data().toInt();
        short deathYear = item -> selectedRows(3).value(0).data().toString() == "Not dead" ? -1 : item -> selectedRows(3).value(0).data().toInt();
        a.setPerson(new Person(name.toStdString(), gender, birthYear, deathYear));
        a.exec();
    } else if(listType == COMPUTER) {
        AddComputerDialog a;
        a.setEntityManager(userInterface.getEntityManager());
        QString name = item -> selectedRows(0).value(0).data().toString();
        short type = 0;
        string machineType = item -> selectedRows(1).value(0).data().toString().toStdString();
        for(int i = 1; i < NUMBER_OF_MACHINES_TYPES; i++) { // no need to check for the first index
            if(machineType == MACHINE_TYPES[i]) {
                type = i;
                break;
            }
        }
        short yearBuilt = item -> selectedRows(2).value(0).data().toString() == "Not built" ? -1 : item -> selectedRows(2).value(0).data().toInt();
        a.setComputer(new Computer(name.toStdString(), yearBuilt, type));
        a.exec();
    }
    tableModel = userInterface.getTableModel(userInterface.getSearchResults(ui -> listSearch -> text().toStdString(), ui -> listFilter -> text().toStdString(), listType), listType);
    ui -> tableView -> setModel(tableModel);
    ui -> editButton -> setEnabled(false);
    ui -> viewButton -> setEnabled(false);
    ui -> removeButton -> setEnabled(false);
    this -> show();
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
        entity = new Computer(name.toStdString(), yearBuilt, type);
    } else {
        entity = userInterface.getConnection(item -> selectedRows(0).value(0).data().toString().toStdString(), item -> selectedRows(1).value(0).data().toString().toStdString());
        name = QString::fromStdString(static_cast<Connection*>(entity) -> getName());
    }
    if(userInterface.removeEntity(entity, name, listType)) {
        tableModel -> removeRow(item -> currentIndex().row(), QModelIndex());
    }
}

void MainWindow::on_tableView_clicked(const QModelIndex&) {
    if(listType != CONNECTION) {
        ui -> editButton -> setEnabled(true);
        ui -> viewButton -> setEnabled(true);
    }
    ui -> removeButton -> setEnabled(true);
}

void MainWindow::on_viewButton_clicked() {
    QItemSelectionModel *item = ui -> tableView -> selectionModel();
    if(listType == PERSON) {
        ViewPersonDialog v;
        v.setEntityManager(userInterface.getEntityManager());
        QString name = item -> selectedRows(0).value(0).data().toString();
        short gender = item -> selectedRows(1).value(0).data().toString() == "Male" ? 0 : 1;
        short birthYear = item -> selectedRows(2).value(0).data().toInt();
        short deathYear = item -> selectedRows(3).value(0).data().toString() == "Not dead" ? -1 : item -> selectedRows(3).value(0).data().toInt();
        v.setPerson(new Person(name.toStdString(), gender, birthYear, deathYear));
        v.exec();
    } else if(listType == COMPUTER) {
        ViewComputerDialog v;
        v.setEntityManager(userInterface.getEntityManager());
        QString name = item -> selectedRows(0).value(0).data().toString();
        short type = 0;
        string machineType = item -> selectedRows(1).value(0).data().toString().toStdString();
        for(int i = 1; i < NUMBER_OF_MACHINES_TYPES; i++) { // no need to check for the first index
            if(machineType == MACHINE_TYPES[i]) {
                type = i;
                break;
            }
        }
        short yearBuilt = item -> selectedRows(2).value(0).data().toString() == "Not built" ? -1 : item -> selectedRows(2).value(0).data().toInt();
        v.setComputer(new Computer(name.toStdString(), yearBuilt, type));
        v.exec();
    }
}

void MainWindow::on_actionSnake_2_triggered() {
    this -> hide();
    bool isOk;
    short gridSize = QInputDialog::getInt(this, QObject::tr("Grid"),
                                       QObject::tr("Grid size(10-30):"), 10, 10, 30, 1, &isOk);
    if(isOk) {
       SnakeHiscoresDialog s;
       s.setData(userInterface.getEntityManager() -> getStorage(), gridSize);
       s.exec();
    }
    this -> show();
}

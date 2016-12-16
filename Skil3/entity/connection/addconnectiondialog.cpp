#include "addconnectiondialog.h"
#include "ui_addconnectiondialog.h"

AddConnectionDialog::AddConnectionDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddConnectionDialog) {
    ui -> setupUi(this);
    ui -> personTable -> setSelectionMode(QAbstractItemView::SingleSelection);
    ui -> personTable -> horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch);
    ui -> computerTable -> setSelectionMode(QAbstractItemView::SingleSelection);
    ui -> computerTable -> horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch);
    setWindowTitle("Add Connection");
    resize(QDesktopWidget().availableGeometry(this).size() * 0.5);
    personId = -1;
    computerId = -1;
}

AddConnectionDialog::~AddConnectionDialog() {
    delete ui;
}

void AddConnectionDialog::setEntityManager(EntityManager *manager) {
    this -> manager = manager;
    personModel = manager -> getTableModel(manager -> getEntities(PERSON), PERSON);
    computerModel = manager -> getTableModel(manager -> getEntities(COMPUTER), COMPUTER);
    ui -> personTable -> setModel(personModel);
    ui -> computerTable -> setModel(computerModel);
}

void AddConnectionDialog::on_personTable_clicked(const QModelIndex&){
    QItemSelectionModel *item = ui -> personTable -> selectionModel();
    personId = item -> currentIndex().row();
    ui -> personLabel -> setText(item -> selectedRows(0).value(0).data().toString());
    if(computerId >= 0 && !ui -> addButton -> isEnabled()) {
        ui -> addButton -> setEnabled(true);
    }
}

void AddConnectionDialog::on_computerTable_clicked(const QModelIndex &) {
    QItemSelectionModel *item = ui -> computerTable -> selectionModel();
    computerId = item -> currentIndex().row();
    ui -> computerLabel -> setText(item -> selectedRows(0).value(0).data().toString());
    if(personId >= 0 && !ui -> addButton -> isEnabled()) {
        ui -> addButton -> setEnabled(true);
    }
}

void AddConnectionDialog::on_addButton_clicked() {
    Person *person = static_cast<Person*>((manager -> getEntities(PERSON))[personId]);
    Computer *computer = static_cast<Computer*>((manager -> getEntities(COMPUTER))[computerId]);
    Connection *connection = new Connection(person -> getID(), computer -> getID());
    connection -> setPerson(person);
    connection -> setComputer(computer);
    vector<Entity*> connections = manager -> getEntities(CONNECTION);
    for(unsigned int i = 0; i < connections.size(); i++) {
        Connection *connection = static_cast<Connection*>(connections[i]);
        if(connection -> getPersonID() == person -> getID() && connection -> getComputerID() == computer -> getID()) {
            QMessageBox errorBox;
            errorBox.critical(0,"Error", "This connection has already been made!");
            errorBox.setFixedSize(500, 200);
            return;
        }
    }
    manager -> add(connection, 2);
    this -> close();
}

void AddConnectionDialog::on_cancelButton_clicked() {
    this -> close();
}

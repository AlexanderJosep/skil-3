#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

AddComputerDialog::AddComputerDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddComputerDialog) {
    ui -> setupUi(this);
}


AddComputerDialog::~AddComputerDialog() {
    delete ui;
}

void AddComputerDialog::setEntityManager(EntityManager *manager) {
    this -> manager = manager;
    ui -> buildYearBox  -> setMinimum(0);
    ui -> buildYearBox -> setMaximum(manager -> getCurrentYear());
}

void AddComputerDialog::on_cancelButton_clicked() {
    this -> close();
}

void AddComputerDialog::on_addButton_clicked() {
    string name = ui -> nameBox -> text().toStdString();
    name = manager -> trim(name);
    if(!manager -> validName(name, 1)) {
        // invalid name
        return;
    }
    short type = ui -> typeBox -> currentIndex();
    short buildYear = ui -> computerBuiltBox -> isChecked() ? ui -> buildYearBox -> value() : -1;
    Computer *computer = new Computer(name, buildYear, type);
    manager -> add(computer, 1);
    this -> close();
}

void AddComputerDialog::on_computerBuiltBox_toggled(bool checked) {
    ui -> buildYearBox -> setEnabled(checked);
}

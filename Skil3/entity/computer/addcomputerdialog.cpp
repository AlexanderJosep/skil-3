#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

AddComputerDialog::AddComputerDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddComputerDialog) {
    ui -> setupUi(this);
    setWindowTitle("Add a computer");
}

AddComputerDialog::~AddComputerDialog() {
    delete ui;
}

void AddComputerDialog::setEntityManager(EntityManager *manager) {
    this -> manager = manager;
    ui -> buildYearBox  -> setMinimum(0);
    ui -> buildYearBox -> setMaximum(manager -> getCurrentYear());
}

void AddComputerDialog::setComputer(Computer *computer) {
    this -> computer = computer;
    this -> edit = true;
    setWindowTitle("Edit computer");
    ui -> addButton -> setText("Save");
    ui -> nameBox-> setText(QString::fromStdString(computer -> getName()));
    ui -> typeBox -> setCurrentIndex(computer -> getType());
    if(computer -> getYear() >= 0) {
        ui -> computerBuiltBox -> setChecked(true);
        ui -> buildYearBox -> setValue(computer -> getYear());
    }
}

void AddComputerDialog::on_cancelButton_clicked() {
    this -> close();
}

void AddComputerDialog::on_addButton_clicked() {
    string name = ui -> nameBox -> text().toStdString();
    name = manager -> trim(name);
    if(!manager -> validName(name, 1)) {
        QMessageBox errorBox;
        errorBox.critical(0,"Error", "Please select a valid name!");
        errorBox.setFixedSize(500, 200);
        return;
    }
    short type = ui -> typeBox -> currentIndex();
    short buildYear = ui -> computerBuiltBox -> isChecked() ? ui -> buildYearBox -> value() : -1;
    Computer *computer = new Computer(name, buildYear, type);
    if(edit) {
        manager -> edit(this -> computer, computer, COMPUTER);
    } else {
        manager -> add(computer, COMPUTER);
    }
    this -> close();
}

void AddComputerDialog::on_computerBuiltBox_toggled(bool checked) {
    ui -> buildYearBox -> setEnabled(checked);
}

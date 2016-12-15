#include "addpersondialog.h"
#include "ui_addpersondialog.h"

AddPersonDialog::AddPersonDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddPersonDialog) {
    ui -> setupUi(this);
}

AddPersonDialog::~AddPersonDialog() {
    delete ui;
}

void AddPersonDialog::setEntityManager(EntityManager *manager) {
    this -> manager = manager;
    ui -> birthYearBox -> setMinimum(0);
    ui -> birthYearBox -> setMaximum(manager -> getCurrentYear());
    ui -> deathYearBox -> setMinimum(0);
    ui -> deathYearBox -> setMaximum(manager -> getCurrentYear());
}

void AddPersonDialog::on_personDeadBox_toggled(bool checked) {
    ui -> deathYearBox -> setEnabled(checked);
}

void AddPersonDialog::on_addButton_clicked() {
    string name = ui -> nameBox -> text().toStdString();
    name = manager -> trim(name);
    name = manager -> capitialize(name);
    if(!manager -> validName(name, 0)) {
        // invalid name
        return;
    }
    short gender = ui-> genderBox -> currentIndex();
    short birthYear = ui -> birthYearBox -> value();
    short deathYear = ui -> personDeadBox-> isChecked() ? ui -> deathYearBox -> value() : -1;
    Person *person = new Person(name, gender, birthYear, deathYear);
    manager -> add(person, 0);
    this -> close();
}

void AddPersonDialog::on_cancelButton_clicked() {
    this -> close();
}

void AddPersonDialog::on_birthYearBox_valueChanged(int arg1) {
    ui -> deathYearBox -> setMinimum(arg1);
}

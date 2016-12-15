#include "addpersondialog.h"
#include "ui_addpersondialog.h"

AddPersonDialog::AddPersonDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddPersonDialog) {
    ui -> setupUi(this);
    setWindowTitle("Add a person");
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

void AddPersonDialog::setPerson(Person *person) {
    this -> person = person;
    this -> edit = true;
    setWindowTitle("Edit person");
    ui -> addButton -> setText("Save");
    ui -> nameBox-> setText(QString::fromStdString(person -> getName()));
    ui -> genderBox -> setCurrentIndex(person -> getGender());
    ui -> birthYearBox -> setValue(person -> getBirthYear());
    if(person -> getDeathYear() >= 0) {
        ui -> personDeadBox -> setChecked(true);
        ui -> deathYearBox -> setValue(person -> getDeathYear());
    }
}

void AddPersonDialog::on_personDeadBox_toggled(bool checked) {
    ui -> deathYearBox -> setEnabled(checked);
}

void AddPersonDialog::on_addButton_clicked() {
    string name = ui -> nameBox -> text().toStdString();
    name = manager -> trim(name);
    name = manager -> capitialize(name);
    if(!manager -> validName(name, 0)) {
        QMessageBox errorBox;
        errorBox.critical(0,"Error", "Please select a valid name!");
        errorBox.setFixedSize(500, 200);
        return;
    }
    short gender = ui -> genderBox -> currentIndex();
    short birthYear = ui -> birthYearBox -> value();
    short deathYear = ui -> personDeadBox -> isChecked() ? ui -> deathYearBox -> value() : -1;
    Person *person = new Person(name, gender, birthYear, deathYear);
    if(edit) {
        manager -> edit(this -> person, person, PERSON);
    } else {
        manager -> add(person, PERSON);
    }
    this -> close();
}

void AddPersonDialog::on_cancelButton_clicked() {
    this -> close();
}

void AddPersonDialog::on_birthYearBox_valueChanged(int arg1) {
    ui -> deathYearBox -> setMinimum(arg1);
}

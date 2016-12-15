#include "addpersondialog.h"
#include "ui_addpersondialog.h"

AddPersonDialog::AddPersonDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddPersonDialog) {
    ui -> setupUi(this);
}

AddPersonDialog::~AddPersonDialog() {
    delete ui;
}

void AddPersonDialog::on_personDeadBox_toggled(bool checked) {
    ui -> deathYearBox -> setEnabled(checked);
}

void AddPersonDialog::on_addButton_clicked() {
    QString name = ui->nameBox -> text();
    int gender = ui->genderBox->currentIndex();
    QString birthYear = ui->birthYearBox->text();
    QString deathYear = ui->deathYearBox->text();

}

void AddPersonDialog::on_cancelButton_clicked() {
    this -> close();
}

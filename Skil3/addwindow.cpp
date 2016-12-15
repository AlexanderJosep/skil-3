#include "addwindow.h"
#include "ui_addwindow.h"

AddWindow::AddWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWindow) {
    ui->setupUi(this);
    ui->deathYearBox->setEnabled(false);
}

AddWindow::~AddWindow() {
    delete ui;
}

void AddWindow::on_addPersonButton_clicked() {
    QString name = ui->nameBox->text();
    int gender = ui->genderBox->currentIndex();
    QString birthYear = ui->birthYearBox->text();
    QString deathYear = ui->deathYearBox->text();
}

void AddWindow::on_cancelButton_clicked() {
    this -> close();
}

void AddWindow::on_isDeadCheckBox_toggled(bool checked) {
    if(checked) {
        ui->deathYearBox->setEnabled(true);
    } else {
        ui->deathYearBox->setEnabled(false);
    }
}

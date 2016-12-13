#include "addwindow.h"
#include "ui_addwindow.h"

AddWindow::AddWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWindow) {
    ui->setupUi(this);
}

AddWindow::~AddWindow() {
    delete ui;
}

void AddWindow::on_pushButton_clicked()
{
    //hellings kóði, með villuleiðbeiningum.
}

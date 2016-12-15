#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "entity/entitymanager.h"
#include "entity/computer/computer.h"

namespace Ui {
class AddComputerDialog;
}

class AddComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerDialog(QWidget *parent = 0);
    ~AddComputerDialog();
    void setEntityManager(EntityManager *manager);
    void setComputer(Computer *computer);
private slots:
     void on_cancelButton_clicked();
     void on_addButton_clicked();
     void on_computerBuiltBox_toggled(bool checked);

private:
    Ui::AddComputerDialog *ui;
    EntityManager *manager;
    Computer *computer;
    bool edit;
};

#endif // ADDCOMPUTERDIALOG_H

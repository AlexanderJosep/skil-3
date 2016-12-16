#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
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
     void on_imageSelection_clicked();
     void on_removeImageButton_clicked();

private:
    Ui::AddComputerDialog *ui;
    EntityManager *manager;
    Computer *computer;
    bool edit;
    bool updatedImage;
    QString imageName;
};

#endif // ADDCOMPUTERDIALOG_H

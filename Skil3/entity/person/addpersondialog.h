#ifndef ADDPERSONDIALOG_H
#define ADDPERSONDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include "entity/entitymanager.h"

namespace Ui {
class AddPersonDialog;
}

class AddPersonDialog : public QDialog {
    Q_OBJECT
public:
    explicit AddPersonDialog(QWidget *parent = 0);
    ~AddPersonDialog();
    void setEntityManager(EntityManager *manager);
    void setPerson(Person *person);
private slots:
    void on_personDeadBox_toggled(bool checked);
    void on_addButton_clicked();
    void on_cancelButton_clicked();
    void on_birthYearBox_valueChanged(int arg1);
    void on_imageSelection_clicked();
    void on_removeImageButton_clicked();

private:
    Ui::AddPersonDialog *ui;
    EntityManager *manager;
    Person *person;
    bool edit;
    bool updatedImage;
    QString imageName;
};

#endif // ADDPERSONDIALOG_H

#ifndef VIEWPERSONDIALOG_H
#define VIEWPERSONDIALOG_H

#include <QDialog>
#include <QDesktopWidget>
#include "entity/entitymanager.h"

namespace Ui {
class ViewPersonDialog;
}

class ViewPersonDialog : public QDialog {
    Q_OBJECT
public:
    explicit ViewPersonDialog(QWidget *parent = 0);
    ~ViewPersonDialog();
    void setEntityManager(EntityManager *manager);
    void setPerson(Person *person);
private slots:
    void on_closeButton_clicked();
private:
    Ui::ViewPersonDialog *ui;
    EntityManager *manager;
    Person *person;
    QString imageName;
};

#endif // VIEWPERSONDIALOG_H

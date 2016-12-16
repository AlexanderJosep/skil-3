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

    /**
    * Sets the entity manager for getting entity lists/data.
    */
    void setEntityManager(EntityManager *manager);

    /**
    * Here we fill all of the widgets with correct information, like change the text of the name box for viewing.
    * We also set the image if the person has a picture of itself.
    */
    void setPerson(Person *person);
private slots:

    /**
    * Close the window then the close button is clicked
    */
    void on_closeButton_clicked();
private:
    Ui::ViewPersonDialog *ui;
    EntityManager *manager;
    Person *person;
    QString imageName;
};

#endif // VIEWPERSONDIALOG_H

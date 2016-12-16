#ifndef VIEWCOMPUTERDIALOG_H
#define VIEWCOMPUTERDIALOG_H

#include <QDialog>
#include "entity/entitymanager.h"
#include "entity/computer/computer.h"

namespace Ui {
class ViewComputerDialog;
}

class ViewComputerDialog : public QDialog {
    Q_OBJECT
public:
    explicit ViewComputerDialog(QWidget *parent = 0);
    ~ViewComputerDialog();

    /**
    * Sets the entity manager for getting entity lists/data.
    */
    void setEntityManager(EntityManager *manager);

    /**
    * Here we fill all of the widgets with correct information, like change the text of the name box for viewing.
    * We also set the image if the computer has a picture of itself.
    */
    void setComputer(Computer *computer);
private slots:
    /**
    * Close the window then the close button is clicked
    */
    void on_closeButtom_clicked();
private:
    Ui::ViewComputerDialog *ui;
    EntityManager *manager;
    Computer *computer;
    QString imageName;
};

#endif // VIEWCOMPUTERDIALOG_H

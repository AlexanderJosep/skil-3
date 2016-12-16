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
    void setEntityManager(EntityManager *manager);
    void setComputer(Computer *computer);
private slots:
    void on_closeButtom_clicked();
private:
    Ui::ViewComputerDialog *ui;
    EntityManager *manager;
    Computer *computer;
    QString imageName;
};

#endif // VIEWCOMPUTERDIALOG_H

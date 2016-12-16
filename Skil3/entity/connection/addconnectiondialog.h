#ifndef ADDCONNECTIONDIALOG_H
#define ADDCONNECTIONDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QAbstractItemView>
#include <QStandardItemModel>
#include "entity/entitymanager.h"
#include "config.h"

using namespace config;

namespace Ui {
class AddConnectionDialog;
}

class AddConnectionDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddConnectionDialog(QWidget *parent = 0);
    ~AddConnectionDialog();

    /**
    * Sets the entity manager for getting entity lists/data.
    */
    void setEntityManager(EntityManager *manager);

private slots:

    /**
    * Here we check if both tables, person and computer have been clicked and enable the Add button if it has.
    */
    void on_personTable_clicked(const QModelIndex &index);

    /**
    * Here we check if both tables, computer and person have been clicked and enable the add button if it has.
    */
    void on_computerTable_clicked(const QModelIndex &index);

    /**
    * Adds a connection between a person and a computer. Also checks if the connection has already been made and
    * tells the user the error if it has been.
    */
    void on_addButton_clicked();

    /**
    * Close the window if the cancel button has been clicked.
    */
    void on_cancelButton_clicked();

    /**
    * Here we check if both tables, person and computer have been clicked and enable the Add button if it has.
    */
    void on_personTable_pressed(const QModelIndex &index);

    /**
    * Here we check if both tables, computer and person have been clicked and enable the add button if it has.
    */
    void on_computerTable_pressed(const QModelIndex &index);

private:
    Ui::AddConnectionDialog *ui;
    EntityManager *manager;
    QStandardItemModel *personModel;
    QStandardItemModel *computerModel;
    int personId;
    int computerId;
};

#endif // ADDCONNECTIONDIALOG_H

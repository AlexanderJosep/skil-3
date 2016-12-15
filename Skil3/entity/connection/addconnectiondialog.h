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
    void setEntityManager(EntityManager *manager);

private slots:
    void on_personTable_clicked(const QModelIndex &index);
    void on_computerTable_clicked(const QModelIndex &index);
    void on_addButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::AddConnectionDialog *ui;
    EntityManager *manager;
    QStandardItemModel *personModel;
    QStandardItemModel *computerModel;
    int personId;
    int computerId;
};

#endif // ADDCONNECTIONDIALOG_H

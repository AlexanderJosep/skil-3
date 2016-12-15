#ifndef ADDPERSONDIALOG_H
#define ADDPERSONDIALOG_H

#include <QDialog>

namespace Ui {
class AddPersonDialog;
}

class AddPersonDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddPersonDialog(QWidget *parent = 0);
    ~AddPersonDialog();

private slots:
    void on_personDeadBox_toggled(bool checked);
    void on_addButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::AddPersonDialog *ui;
};

#endif // ADDPERSONDIALOG_H

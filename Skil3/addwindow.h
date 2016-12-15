#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>

namespace Ui {
class AddWindow;
}

class AddWindow : public QDialog {
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = 0);
    ~AddWindow();

private slots:
    void on_addPersonButton_clicked();

private:
    Ui::AddWindow *ui;
};

#endif // ADDWINDOW_H

#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>

namespace Ui {
class EditWindow;
}

class EditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = 0);
    ~EditWindow();

private slots:

    void on_edButton_clicked();

private:
    Ui::EditWindow *ui;
};

#endif // EDITWINDOW_H

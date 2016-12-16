#ifndef SNAKEHISCORESDIALOG_H
#define SNAKEHISCORESDIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDesktopWidget>
#include "storage/storage.h"
#include "snakescore.h"

namespace Ui {
class SnakeHiscoresDialog;
}

class SnakeHiscoresDialog : public QDialog {
    Q_OBJECT
public:
    explicit SnakeHiscoresDialog(QWidget *parent = 0);
    ~SnakeHiscoresDialog();
    /**
    * Sets the table contents. Retrieves hiscore data from a sql database in storage.
    */
    void setData(Storage *storage, int grid);
private slots:
    /**
    * Close the frame when close clicked.
    */
    void on_closeButton_clicked();
private:
    Ui::SnakeHiscoresDialog *ui;
};

#endif // SNAKEHISCORESDIALOG_H

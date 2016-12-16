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
    void setData(Storage *storage, int grid);
private slots:
    void on_closeButton_clicked();
private:
    Ui::SnakeHiscoresDialog *ui;
};

#endif // SNAKEHISCORESDIALOG_H

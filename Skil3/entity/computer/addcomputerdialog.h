#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include "entity/entitymanager.h"
#include "entity/computer/computer.h"

namespace Ui {
class AddComputerDialog;
}

class AddComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerDialog(QWidget *parent = 0);
    ~AddComputerDialog();

    /**
    * Sets the entity manager for getting entity lists/data.
    */
    void setEntityManager(EntityManager *manager);

    /**
    * When we want to edit a computer we use this function. Here we change
    * text of buttons & title as well as fill in the info so the user won't have to.
    */
    void setComputer(Computer *computer);
private slots:

    /**
    * Close the frame when the cancel button is clicked
    */
     void on_cancelButton_clicked();

     /**
     * Add/edit the computer when the add/edit button is clicked. If an image was chosen it is copied
     * and moved to a folder for future loading.
     */
     void on_addButton_clicked();

     /**
     * Check or uncheck whether the computer was built and enable/disable the computer built input box.
     */
     void on_computerBuiltBox_toggled(bool checked);

     /**
     * Select an image with a file selector and gets the path of it
     */
     void on_imageSelection_clicked();

     /**
     * Clears the image and sets it to the default one
     */
     void on_removeImageButton_clicked();

private:
    Ui::AddComputerDialog *ui;
    EntityManager *manager;
    Computer *computer;
    bool edit;
    bool updatedImage;
    QString imageName;
};

#endif // ADDCOMPUTERDIALOG_H

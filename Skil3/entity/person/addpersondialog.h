#ifndef ADDPERSONDIALOG_H
#define ADDPERSONDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include "entity/entitymanager.h"

namespace Ui {
class AddPersonDialog;
}

class AddPersonDialog : public QDialog {
    Q_OBJECT
public:
    explicit AddPersonDialog(QWidget *parent = 0);
    ~AddPersonDialog();

    /**
    * Sets the entity manager for getting entity lists/data.
    */
    void setEntityManager(EntityManager *manager);

    /**
    * When we want to edit a computer we use this function. Here we change
    * text of buttons & title as well as fill in the info so the user won't have to.
    */
    void setPerson(Person *person);
private slots:

    /**
    * Check or uncheck whether the computer was dead or not and enables/disables the death year input box.
    */
    void on_personDeadBox_toggled(bool checked);

    /**
    * Add/edit the person when the add/edit button is clicked. If an image was chosen it is copied
    * and moved to a folder for future loading.
    */
    void on_addButton_clicked();

    /**
    * Closes the frame when the cancel button is clicked
    */
    void on_cancelButton_clicked();

    /**
    * If the birth year is changed we must change the minimum value for death year because the person can't be born
    * after it's died. Here we change that.
    */
    void on_birthYearBox_valueChanged(int arg1);

    /**
    * Select an image with a file selector and gets the path of it
    */
    void on_imageSelection_clicked();

    /**
    * Clears the image and sets it to the default one
    */
    void on_removeImageButton_clicked();

private:
    Ui::AddPersonDialog *ui;
    EntityManager *manager;
    Person *person;
    bool edit;
    bool updatedImage;
    QString imageName;
};

#endif // ADDPERSONDIALOG_H

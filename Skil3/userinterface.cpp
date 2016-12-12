#include "userinterface.h"

UserInterface::UserInterface() {
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    this -> manager = EntityManager(tPtr -> tm_year + 1900); // parameter is the current year
}

QStandardItemModel* UserInterface::getPersonTableModel(int organization, MainWindow *window) {
    vector<Entity*> entities = manager.getOrganizedEntities(organization, PERSON);
    QStandardItemModel *model = new QStandardItemModel(entities.size(), 4, window);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Gender")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Birth year")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Death year")));
    for(unsigned int i = 0; i < entities.size(); i++) {
        Person* person = static_cast<Person*>(entities[i]);
        QStandardItem *row1 = new QStandardItem(QString::fromStdString(person -> getName()));
        model->setItem(i, 0, row1);
        string gender = person -> getGender() == 0 ? "Male" : "Female";
        QStandardItem *row2 = new QStandardItem(QString::fromStdString(gender));
        model->setItem(i, 1, row2);
        QStandardItem *row3 = new QStandardItem(QString::fromStdString(to_string(person -> getBirthYear())));
        model->setItem(i, 2, row3);
        string deathYear = person -> getDeathYear() < 0 ? "Not dead" : to_string(person -> getDeathYear());
        QStandardItem *row4 = new QStandardItem(QString::fromStdString(deathYear));
        model->setItem(i, 3, row4);
    }
    return model;

}


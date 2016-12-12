#include "userinterface.h"

UserInterface::UserInterface() {
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    this -> manager = EntityManager(tPtr -> tm_year + 1900); // parameter is the current year
}

QStandardItemModel* UserInterface::getTableModel(int type, int organization, QMainWindow *window) {

    vector<Entity*> entities = manager.getOrganizedEntities(organization, type);
    QStandardItemModel *model = new QStandardItemModel(entities.size(), 4 - type, window);
    model -> setHorizontalHeaderItem(0, new QStandardItem(QString(type == CONNECTION ? "Person" : "Name")));
    model -> setHorizontalHeaderItem(1, new QStandardItem(QString(type == CONNECTION ? "Computer" : (type == COMPUTER ? "Type" : "Gender"))));
    if(type != CONNECTION) {
        model -> setHorizontalHeaderItem(2, new QStandardItem(QString(type == COMPUTER ? "Year built" : "Birth year")));
        if(type == PERSON) {
            model -> setHorizontalHeaderItem(3, new QStandardItem(QString("Death year")));
        }
    }
    for(unsigned int i = 0; i < entities.size(); i++) {
        if(type == PERSON) {
            Person* person = static_cast<Person*>(entities[i]);
            QStandardItem *row1 = new QStandardItem(QString::fromStdString(person -> getName()));
            string gender = person -> getGender() == 0 ? "Male" : "Female";
            QStandardItem *row2 = new QStandardItem(QString::fromStdString(gender));
            QStandardItem *row3 = new QStandardItem(QString::fromStdString(to_string(person -> getBirthYear())));
            string deathYear = person -> getDeathYear() < 0 ? "Not dead" : to_string(person -> getDeathYear());
            QStandardItem *row4 = new QStandardItem(QString::fromStdString(deathYear));
            model -> setItem(i, 0, row1);
            model -> setItem(i, 1, row2);
            model -> setItem(i, 2, row3);
            model -> setItem(i, 3, row4);
        } else if(type == COMPUTER) {
            Computer* computer = static_cast<Computer*>(entities[i]);
            QStandardItem *row1 = new QStandardItem(QString::fromStdString(computer -> getName()));
            QStandardItem *row2 = new QStandardItem(QString::fromStdString(MACHINE_TYPES[computer -> getType()]));
            string built = computer -> getYear() < 0 ? "Not built" : to_string(computer -> getYear());
            QStandardItem *row3 = new QStandardItem(QString::fromStdString(built));
            model -> setItem(i, 0, row1);
            model -> setItem(i, 1, row2);
            model -> setItem(i, 2, row3);
        } else {
            Connection* connection = static_cast<Connection*>(entities[i]);
            QStandardItem *row1 = new QStandardItem(QString::fromStdString(connection -> getComputer() -> getName()));
            QStandardItem *row2 = new QStandardItem(QString::fromStdString(connection -> getPerson() -> getName()));
            model -> setItem(i, 0, row1);
            model -> setItem(i, 1, row2);
        }
    }
    return model;

}


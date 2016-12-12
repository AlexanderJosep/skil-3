#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <cstdlib>
#include <QStandardItemModel>
#include "mainwindow.h"
#include "config.h"
#include "entity.h"
#include "person.h"
#include "computer.h"
#include "connection.h"
#include "entitymanager.h"

using namespace config;

class UserInterface {
public:
    UserInterface();
    QStandardItemModel* getPersonTableModel(int organization, MainWindow *window);
private:
    int currentYear;
    EntityManager manager;
};

#endif // USERINTERFACE_H

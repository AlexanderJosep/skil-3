#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <cstdlib>
#include <QStandardItemModel>
#include <QMainWindow>
#include <vector>
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
    QStandardItemModel* getTableModel(vector<Entity*> entities, int type, QMainWindow *window);
    vector<Entity*> getEntities(int type);
    vector<Entity*> getSearchResults(string s, string filter, int type);
private:
    int currentYear;
    EntityManager manager;
};

#endif // USERINTERFACE_H

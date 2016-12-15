#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <cstdlib>
#include <QStandardItemModel>
#include <QMainWindow>
#include <QMessageBox>
#include <vector>
#include "config.h"
#include "entity/entity.h"
#include "entity/person/person.h"
#include "entity/computer/computer.h"
#include "entity/connection/connection.h"
#include "entity/entitymanager.h"

using namespace config;

class UserInterface {
public:
    UserInterface();
    bool removeEntity(QMainWindow *window, Entity *entity, QString s, int type);
    Connection* getConnection(string person, string computer);
    QStandardItemModel* getTableModel(vector<Entity*> entities, int type, QMainWindow *window);
    vector<Entity*> getEntities(int type);
    vector<Entity*> getSearchResults(string s, string filter, int type);
private:
    int currentYear;
    EntityManager manager;
};

#endif // USERINTERFACE_H

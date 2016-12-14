#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <cstdlib>
#include <QStandardItemModel>
#include <QMainWindow>
#include <QMessageBox>
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
    void remoteEntity(QMainWindow *window, Entity &entity, string s, int type);
    QStandardItemModel* getTableModel(vector<Entity*> entities, int type, QMainWindow *window);
    vector<Entity*> getEntities(int type);
    vector<Entity*> getSearchResults(string s, string filter, int type);
private:
    int currentYear;
    EntityManager manager;
};

#endif // USERINTERFACE_H

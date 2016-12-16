#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <cstdlib>
#include <QStandardItemModel>
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
    /**
    * Returns the entity manager
    */
    EntityManager* getEntityManager();

    /**
    * Removes an entity from a list in manager and removes it from the sql database it's stored in
    */
    bool removeEntity(Entity *entity, QString s, int type);

    /**
    * Gets a connection based off a person and computer name
    */
    Connection* getConnection(string person, string computer);
private:
    int currentYear;
    EntityManager *manager;
};

#endif // USERINTERFACE_H

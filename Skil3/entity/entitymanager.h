#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <QStandardItemModel>
#include <vector>
#include "config.h"
#include "storage/storage.h"
#include "entity/person/person.h"
#include "entity/computer/computer.h"
#include "entity/connection/connection.h"
#include "snake/snakescore.h"

using namespace config;

class EntityManager {
public:
    EntityManager();
    EntityManager(int currentYear);
    int getCurrentYear();
    void loadConnections();
    Storage* getStorage();
    QStandardItemModel* getTableModel(vector<Entity*> entities, int type);
    bool add(Entity *entity, int type); // adds a entity to the list
    void edit(Entity *oldEntity, Entity *newEntity, int type); // edits a entity in a list
    bool remove(Entity *entity, int type); // remove a entity from a list
    short getID(Entity *entity, int type); // gets the sql id from
    bool validName(string name, int type); // checks if a name is valid or not
    string trim(string s); // trims the edges of a string for any pesky spaces
    string capitialize(string s); // capitalizes a string
    vector<Entity*> getEntities( int type); // gets all entities
    vector<Entity*> getFilteredSearchResults(string searchString, string filterString, int type); // gets filtered search results and returns the resulting entities in a vector
private:
    short getIndex(Entity *entity, int type); // gets a entity index from the list
    string toLowerCase(string s); // lowercases a string
    vector<Entity*> getSearchResults(string search, int type); // returns a list of entities that correspond to the search
    vector<Person> persons;
    vector<Computer> computers;
    vector<Connection> connections;
    Storage storage;
    int currentYear;
};

#endif // ENTITYMANAGER_H

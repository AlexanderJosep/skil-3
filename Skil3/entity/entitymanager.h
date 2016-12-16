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

    /**
    * Returns the current year
    */
    int getCurrentYear();

    /**
    * Loads all connections id's and connects the persons and computers together.
    */
    void loadConnections();

    /**
    * Returns the pointer of the storage object
    */
    Storage* getStorage();

    /**
    * Sets up the table model with its columns and rows and returns it.
    */
    QStandardItemModel* getTableModel(vector<Entity*> entities, int type);

    /**
    * Adds a entity to the list and stores it
    */
    bool add(Entity *entity, int type);

    /**
    * Edits an entity, oldEntity having the old information and newEntity having the new information, and updates it in the database.
    */
    void edit(Entity *oldEntity, Entity *newEntity, int type);

    /**
    * Removes an entity from a list and removes it from the database
    */
    bool remove(Entity *entity, int type);

    /**
    * Returns the entities sql id
    */
    short getID(Entity *entity, int type);

    /**
    * Checks if a name is valid or not depending on the entity type
    */
    bool validName(string name, int type);

    /**
    * Trims the edges of a string for any pesky spaces
    */
    string trim(string s);

    /**
    * Capitalize a string
    */
    string capitalize(string s);

    /**
    * Returns a list of pointers to entities
    */
    vector<Entity*> getEntities(int type);

    /**
    * Returns a list of pointers to searched and filtered entities
    */
    vector<Entity*> getFilteredSearchResults(string searchString, string filterString, int type);
private:

    /**
    * Returns the index of entity in its list
    */
    short getIndex(Entity *entity, int type);

    /**
    * Lowercases a string
    */
    string toLowerCase(string s);

    /**
    * Returns a list of pointers to searched entities
    */
    vector<Entity*> getSearchResults(string search, int type); // returns a list of entities that correspond to the search

    vector<Person> persons;
    vector<Computer> computers;
    vector<Connection> connections;
    Storage storage;
    int currentYear;
};

#endif // ENTITYMANAGER_H

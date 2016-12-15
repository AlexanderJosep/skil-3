#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include "config.h"
#include "console.h"
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
    void loadConnections();
    void add(Console &c, int type);
    void edit(Console &c, vector<Entity*> entities, int type); // edits a entity in a list
    bool remove(Entity *entity, int type); // remove a entity from a list
    vector<Entity*> getOrganizedEntities(int o, int type); // gets organized entity list which organizes by type o
    vector<Entity*> getFilteredSearchResults(string searchString, string filterString, int type); // gets filtered search results and returns the resulting entities in a vector
    void addSnakeScore(Console &c, int score, int grid); // adds a snake score to a list, also prints top 10 hiscores if available
private:
    short getIndex(Entity *entity, int type); // gets a entity index from the list
    string getName(Console &c, bool n, int type); // gets the name from user input, n is true if user is creating a new person, false if editing
    short getGender(Console &c, bool n); // gets the gender from user input, n is true if user is creating a new person, false if editing
    short getYear(Console &c, string s); // gets a year from user input
    short getDeathYear(Console &c, bool n, int birthYear); // gets the death year from user input, n is true if user is creating a new person, false if editing
    short getComputerType(Console &c, string s); // gets a computer type from user input
    short getYearBuilt(Console &c, bool n);
    bool validName(string name, int type); // checks if a name is valid or not
    string trim(string s); // trims the edges of a string for any pesky spaces
    string capitialize(string s); // capitalizes a string
    string toLowerCase(string s); // lowercases a string
    vector<Entity*> getSearchResults(string search, int type); // returns a list of entities that correspond to the search
    vector<Person> persons;
    vector<Computer> computers;
    vector<Connection> connections;
    Storage storage;
    int currentYear;
};

#endif // ENTITYMANAGER_H

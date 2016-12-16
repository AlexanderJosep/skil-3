#ifndef CONNECTION_H
#define CONNECTION_H

#include "entity/entity.h"
#include "entity/person/person.h"
#include "entity/computer/computer.h"

class Connection : public Entity {
public:
    Connection(int personID, int computerID);

    /**
    * Returns the persons's sql id
    */
    int getPersonID();

    /**
    * Returns the computers's sql id
    */
    int getComputerID();

    /**
    * Returns the string: 'name of the person' <-> 'name of the computer'
    */
    string getName();

    /**
    * Sets the pointer to the person. We do this to get future information from it.
    */
    void setPerson(Person *person);

    /**
    * Sets the pointer to the computer. We do this to get future information from it.
    */
    void setComputer(Computer *computer);

    /**
    * Returns the pointer to the person
    */
    Person* getPerson();

    /**
    * Returns the pointer to the computer
    */
    Computer* getComputer();
private:
    int personID;
    int computerID;
    Person *person;
    Computer *computer;
};

#endif // CONNECTION_H

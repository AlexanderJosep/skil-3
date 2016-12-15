#ifndef CONNECTION_H
#define CONNECTION_H

#include "entity/entity.h"
#include "entity/person/person.h"
#include "entity/computer/computer.h"

class Connection : public Entity {
public:
    Connection(int personID, int computerID);
    int getPersonID(); // get person id
    int getComputerID(); // get computer id
    string getName();
    void setPerson(Person *person);
    void setComputer(Computer *computer);
    Person* getPerson();
    Computer* getComputer();
private:
    int personID;
    int computerID;
    Person *person;
    Computer *computer;
};

#endif // CONNECTION_H

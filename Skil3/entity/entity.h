#ifndef ENTITY_H
#define ENTITY_H

#include <sstream>
#include <iomanip>
#include <string>
#include "config.h"

using namespace config;

class Entity {
public:
    Entity();

    /**
    * Returns the overridden name
    */
    virtual string getName();

    /**
    * Returns the sql id of the entity
    */
    int getID();

    /**
    * Sets the sql id of the entity
    */
    void setID(int id);
protected:
    string name;
    int id;
};

#endif // ENTITY_H

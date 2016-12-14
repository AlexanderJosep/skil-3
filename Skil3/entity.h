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
    virtual string getName();
    int getID();
    void setID(int id);
protected:
    string name;
    int id;
};

#endif // ENTITY_H

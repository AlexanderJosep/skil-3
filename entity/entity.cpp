#include "entity.h"

Entity::Entity() {

}

string Entity::getName() {
    return name;
}

int Entity::getID() {
    return id;
}

void Entity::setID(int id) {
    this -> id = id;
}

#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include "entity/entity.h"

using namespace std;

class Person : public Entity {
public:
    Person(string name, short gender, short birthYear, short deathYear);

    /**
    * Returns the gender of the person (0=male, 1=female)
    */
    short getGender();

    /**
    * Returns the birth year of the person
    */
    short getBirthYear();

    /**
    * Returns the death year of the person, if the person isn't dead it returns -1
    */
    short getDeathYear();

    /**
    * When editing the person, we update the name, gender, birth year and death year with the following params
    */
    void setData(string name, short gender, short birthYear, short deathYear);
private:
    short gender;
    short birthYear;
    short deathYear;
};

#endif // PERSON_H

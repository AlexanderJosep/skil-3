#include "person.h"

Person::Person(string name, short gender, short birthYear, short deathYear) {
    this -> name = name;
    this -> gender = gender;
    this -> birthYear = birthYear;
    this -> deathYear = deathYear;
}

short Person::getGender() {
    return gender;
}

short Person::getBirthYear() {
    return birthYear;
}

short Person::getDeathYear() {
    return deathYear;
}

void Person::setData(string name, short gender, short birthYear, short deathYear) {
    this -> name = name;
    this -> gender = gender;
    this -> birthYear = birthYear;
    this -> deathYear = deathYear;
}

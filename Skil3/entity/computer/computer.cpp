#include "computer.h"

Computer::Computer(string name, short year, short type) {
    this -> name = name;
    this -> year = year;
    this -> type = type;
}

short Computer::getYear() {
    return year;
}

short Computer::getType() {
    return type;
}

void Computer::setData(string name, short year, short type) {
    this -> name = name;
    this -> year = year;
    this -> type = type;
}

#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include "entity/entity.h"

using namespace std;

class Computer : public Entity{
public:
    Computer(string name, short year, short type);
    short getYear();
    short getType();
    void setData(string name, short year, short type);
private:
    short year;
    short type;
};

#endif // COMPUTER_H

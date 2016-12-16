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

    /**
    * Returns the year the computer was built. It returns -1 if it wasn't built.
    */
    short getYear();

    /**
    * Gets the type of the computer (0=mechanic, 1=electronic, 2=transistor, 3=quantum)
    */
    short getType();

    /**
    * When editing the computer, we update the name, year and type with the following params
    */
    void setData(string name, short year, short type);
private:
    short year;
    short type;
};

#endif // COMPUTER_H

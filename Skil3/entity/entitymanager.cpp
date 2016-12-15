#include "entitymanager.h"

EntityManager::EntityManager() {

}

EntityManager::EntityManager(int currentYear) {
    this -> currentYear = currentYear;
    this -> persons = storage.getPersons();
    this -> computers = storage.getComputers();
    this -> connections = storage.getConnections();
    loadConnections();
}

int EntityManager::getCurrentYear() {
    return currentYear;
}

void EntityManager::loadConnections() {
    this -> connections = storage.getConnections();
    // set the person and computer pointer in connections
    // we're setting this to get a correct output when displaying connections in the console
    for(unsigned int i = 0; i < connections.size(); i++) {
       for(unsigned int j = 0; j < persons.size(); j++) {
            if(persons[j].getID() == connections[i].getPersonID()) {
                connections[i].setPerson(&persons[j]);
                break;
            }
        }
       for(unsigned int j = 0; j < computers.size(); j++) {
            if(computers[j].getID() == connections[i].getComputerID()) {
                connections[i].setComputer(&computers[j]);
                break;
            }
        }
    }
}

Storage* EntityManager::getStorage() {
    return &storage;
}

QStandardItemModel* EntityManager::getTableModel(vector<Entity*> entities, int type) {
    QStandardItemModel *model = new QStandardItemModel(entities.size(), 4 - type);
    model -> setHorizontalHeaderItem(0, new QStandardItem(QString(type == CONNECTION ? "Person" : "Name")));
    model -> setHorizontalHeaderItem(1, new QStandardItem(QString(type == CONNECTION ? "Computer" : (type == COMPUTER ? "Type" : "Gender"))));
    if(type != CONNECTION) {
        model -> setHorizontalHeaderItem(2, new QStandardItem(QString(type == COMPUTER ? "Year built" : "Birth year")));
        if(type == PERSON) {
            model -> setHorizontalHeaderItem(3, new QStandardItem(QString("Death year")));
        }
    }
    for(unsigned int i = 0; i < entities.size(); i++) {
        if(type == PERSON) {
            Person* person = static_cast<Person*>(entities[i]);
            QStandardItem *row1 = new QStandardItem(QString::fromStdString(person -> getName()));
            string gender = person -> getGender() == 0 ? "Male" : "Female";
            QStandardItem *row2 = new QStandardItem(QString::fromStdString(gender));
            QStandardItem *row3 = new QStandardItem(QString::fromStdString(to_string(person -> getBirthYear())));
            string deathYear = person -> getDeathYear() < 0 ? "Not dead" : to_string(person -> getDeathYear());
            QStandardItem *row4 = new QStandardItem(QString::fromStdString(deathYear));
            model -> setItem(i, 0, row1);
            model -> setItem(i, 1, row2);
            model -> setItem(i, 2, row3);
            model -> setItem(i, 3, row4);
        } else if(type == COMPUTER) {
            Computer* computer = static_cast<Computer*>(entities[i]);
            QStandardItem *row1 = new QStandardItem(QString::fromStdString(computer -> getName()));
            QStandardItem *row2 = new QStandardItem(QString::fromStdString(MACHINE_TYPES[computer -> getType()]));
            string built = computer -> getYear() < 0 ? "Not built" : to_string(computer -> getYear());
            QStandardItem *row3 = new QStandardItem(QString::fromStdString(built));
            model -> setItem(i, 0, row1);
            model -> setItem(i, 1, row2);
            model -> setItem(i, 2, row3);
        } else {
            Connection* connection = static_cast<Connection*>(entities[i]);
            QStandardItem *row1 = new QStandardItem(QString::fromStdString(connection -> getPerson() -> getName()));
            QStandardItem *row2 = new QStandardItem(QString::fromStdString(connection -> getComputer() -> getName()));
            model -> setItem(i, 0, row1);
            model -> setItem(i, 1, row2);
        }
    }
    return model;
}

bool EntityManager::add(Entity *entity, int type) {
    if(type == PERSON) {
        Person *person = static_cast<Person*>(entity);
        if(storage.savePerson(*person)) {
            persons.push_back(*person);
            return true;
        }
    } else if(type == COMPUTER) {
        Computer *computer = static_cast<Computer*>(entity);
        if(storage.saveComputer(*computer)) {
            computers.push_back(*computer);
            return true;
        }
    } else {
        Connection *connection = static_cast<Connection*>(entity);
        if(storage.addConnection(*connection)) {
            connections.push_back(*connection);
            return true;
        }
    }
    return false;
}

void EntityManager::edit(Entity *oldEntity, Entity *newEntity, int type) {
    short index = getIndex(oldEntity, type);
    if(type == PERSON) {
        Person *person = static_cast<Person*>(newEntity);
        if(storage.editPerson(person, persons[index].getName(), persons[index].getGender(), persons[index].getBirthYear(), persons[index].getDeathYear())) {
            persons[index].setData(person -> getName(), person -> getGender(), person -> getBirthYear(), person -> getDeathYear());
        }
    } else if(type == COMPUTER) {
        Computer *computer = static_cast<Computer*>(newEntity);
        if(storage.editComputer(computer, computers[index].getName(), computers[index].getYear(), computers[index].getType())) {
            computers[index].setData(computer -> getName(), computer -> getYear(), computer -> getType());
        }
    }
}

bool EntityManager::remove(Entity *entity, int type) {
    short index = getIndex(entity, type);
    if(index < 0) {
       return false;
    }
    if(type == PERSON) {
        if(storage.removePerson(persons[index])) {
            persons.erase(persons.begin() + index);
        } else {
            return false;
        }
    } else if(type == COMPUTER) {
        if(storage.removeComputer(computers[index])) {
            computers.erase(computers.begin() + index);
        } else {
            return false;
        }
    } else {
        if(storage.removeConnection(connections[index])) {
            connections.erase(connections.begin() + index);
        } else {
            return false;
        }
    }
    loadConnections();
    return true;
}

short EntityManager::getIndex(Entity *entity, int type) {
    short index = -1;
    if(type == PERSON) {
        Person *person = static_cast<Person*>(entity);
        for(unsigned int i = 0; i < persons.size(); i++) {
            if(person -> getName() == persons[i].getName()) {
                if(persons[i].getGender() == person -> getGender()
                        && persons[i].getBirthYear() == person -> getBirthYear() && persons[i].getDeathYear() == person -> getDeathYear()) {
                    index = i;
                    break;
                }
            }
        }
    } else if(type == COMPUTER){
        Computer *computer = static_cast<Computer*>(entity);
        for(unsigned int i = 0; i < computers.size(); i++) {
            if(computers[i].getName() == computer -> getName() && computers[i].getYear() == computer -> getYear() &&
                    computers[i].getType() == computer -> getType()) {
                index = i;
                break;
            }
        }
    } else {
        Connection *connection = static_cast<Connection*>(entity);
        for(unsigned int i = 0; i < connections.size(); i++) {
            if(connection -> getName() == connections[i].getName()) {
                index = i;
                break;
            }
        }
    }
    return index;
}

short EntityManager::getID(Entity *entity, int type) {
    short index = getIndex(entity, type);
    if(index < 0) {
        return -1;
    }
    if(type == PERSON) {
        return persons[index].getID();
    } else if(type == COMPUTER) {
        return computers[index].getID();
    }
    return -1;
}

string EntityManager::getName(Console &c, bool n, int type) {
    string s = n ? "Name" : "New name";
    string name = c.getString(s, true);
    while(true) {
        name = trim(name);
        if(validName(name, type)) {
           if(type != COMPUTER) { // computers shouildn't have to be capitalized (IBM, BBC Micro & more)
                name = capitialize(name);
           }
           break;
        } else {
            c.println("Invalid name!");
            name = c.getString(s, false);
        }
    }
    return name;
}

short EntityManager::getGender(Console &c, bool n) {
    string s = n ? "Gender" : "New gender";
    short gender;
    while(true) {
        c.ignoreNextClear();
        gender = !c.getBool(s, 'm', 'f');
        break;
    }
    return gender;
}

short EntityManager::getYear(Console &c, string s) {
    short year;
    while (true){
        year = c.getShort(s);
        if(year > 0 && year <= currentYear) { // disallow future years and years 0 + b.c.
            break;
        }
        c.println("Invalid year!");
    }
    return year;
}

short EntityManager::getDeathYear(Console &c, bool n, int birthYear) {
    short deathYear = -1;
    if(c.getBool("Person dead", 'y', 'n')) {
        while(true) {
            string s = n ? "Death year" : "New death year";
            deathYear = c.getShort(s);
            if(deathYear >= birthYear && deathYear <= currentYear) { // disallow years before birth year and future years
                break;
            }
            c.println("Please choose a death year the same or after the birth year.");
        }
    }
    return deathYear;
}

short EntityManager::getComputerType(Console &c, string s) {
    short type;
    c.ignoreNextClear();
    while (true){
        // print out all computer types
        c.print("Computer types (ID in parenthesis): ");
        for(int i = 0; i < NUMBER_OF_MACHINES_TYPES; i++) {
            c.print(MACHINE_TYPES[i]+"("+to_string(i + 1)+")");
            if(i + 1 >= NUMBER_OF_MACHINES_TYPES) {
                c.newLine();
            } else if(i + 2 < NUMBER_OF_MACHINES_TYPES) {
                c.print(", ");
            } else {
                c.print(" and ");
            }
        }
        type = c.getShort(s);
        if(type > 0 && type <= NUMBER_OF_MACHINES_TYPES) {
            break;
        }
        c.println("Invalid type!");
    }
    return type - 1;
}

short EntityManager::getYearBuilt(Console &c, bool n) {
    short yearBuilt = -1;
    if(c.getBool("Was the computer built", 'y', 'n')) {
        while(true) {
            string s = n ? "Year built" : "New year built";
            yearBuilt = c.getShort(s);
            if(yearBuilt > 0 && yearBuilt <= currentYear) { // disallow future years and years 0 + b.c.
                break;
            }
            c.println("Please choose a valid year.");
        }
    }
    return yearBuilt;
}

vector<Entity*> EntityManager::getEntities(int type) {
    vector<Entity*> out;
    if(type == PERSON) {
        for(unsigned int i = 0; i < persons.size(); i++) {
            out.push_back(&persons[i]);
        }
    }
    if(type == COMPUTER) {
        for(unsigned int i = 0; i < computers.size(); i++) {
            out.push_back(&computers[i]);
        }
    }
    if(type == CONNECTION) {
        loadConnections();
        for(unsigned int i = 0; i < connections.size(); i++) {
            out.push_back(&connections[i]);
        }
    }
    return out;
}


bool EntityManager::validName(string name, int type) {
    if(name.length() <= 0 || name.find("  ") != string::npos) {
        return false;
    }
    if(type == PERSON) { // computers should be able to have numbers and special chars as names
        for(unsigned int i = 0; i < name.length(); i++) {
            if(!isalpha(name[i]) && name[i] != 32) {
                return false;
            }
        }
    }
    return true;
}

string EntityManager::trim(string s) {
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string EntityManager::capitialize(string s) {
    s = toLowerCase(s); // lowercase everything first before we capitalize the first letter in a word
    const char* c = s.c_str();
    bool capitalizeNext = true;
    char out[s.length() - 1];
    for(unsigned int i = 0; i <= s.length(); i++) {
        out[i] = *(c + i);
        if(capitalizeNext && out[i] != ' ') {
            capitalizeNext = false;
            if(isalpha(out[i])) { // capitalize the char if it is actually a letter
                out[i] -= 32;
            }
        }
        if(out[i] == ' ') {
            capitalizeNext = true;
        }
    }
    return string(out);
}

string EntityManager::toLowerCase(string s) {
    string out;
    out.resize(s.size());
    transform(s.begin(), s.end(), out.begin(), ::tolower);
    return out;
}

vector<Entity*> EntityManager::getFilteredSearchResults(string searchString, string filterString, int type) {
    loadConnections();
    vector<Entity*> search = getSearchResults(searchString, type);
    if(filterString.size() > 0) {
        // we get the filter and search results then remove the filter results from the search result and return it
        vector<Entity*> filter = getSearchResults(filterString, type);
        for(unsigned int i = 0; i < filter.size(); i++) {
            for(unsigned int j = 0; j < search.size(); j++) {
                if(filter[i] -> getID() == search[j] -> getID()) {
                    search.erase(search.begin() + j);
                    break;
                }
            }
        }
    }
    return search;
}

vector<Entity*> EntityManager::getSearchResults(string search, int type) {
    search = toLowerCase(search);
    vector<Entity*> out;
    if(type == PERSON) {
        string male = "male";
        string female = "female";
        string notDead = "not dead";
        for(unsigned int i = 0; i < persons.size(); i++) {
            if(toLowerCase(persons[i].getName()).find(search) != string::npos || to_string(persons[i].getBirthYear()).find(search) != string::npos
                    || (persons[i].getGender() == 0 && male.find(search) != string::npos) || (search != male && persons[i].getGender() == 1 && female.find(search) != string::npos)
                    || (persons[i].getDeathYear() >= 0 && to_string(persons[i].getDeathYear()).find(search) != string::npos) || (persons[i].getDeathYear() < 0 && notDead.find(search) != string::npos)) {
               out.push_back(&persons[i]);
            }
        }
    }
    if(type == COMPUTER) {
        string built = "built";
        string notBuilt = "not built";
        for(unsigned int j = 0; j < computers.size(); j++) {
            bool added = false;
            for(int i = 0; i < NUMBER_OF_MACHINES_TYPES; i++) {
                if(computers[j].getType() == i) {
                    if(toLowerCase(MACHINE_TYPES[i]).find(search) != string::npos) {
                        out.push_back(&computers[j]);
                        added = true;
                    }
                    break;
                }
            }
            if(added) {
                continue;
            }
            if(toLowerCase(computers[j].getName()).find(search) != string::npos || (computers[j].getYear() && to_string(computers[j].getYear()).find(search) != string::npos)
                    || (computers[j].getYear() >= 0 && built.find(search) != string::npos) || (search != built && computers[j].getYear() < 0 && notBuilt.find(search) != string::npos)) {
               out.push_back(&computers[j]);
            }
        }
    }
    if(type == CONNECTION) {
        for(unsigned int j = 0; j < connections.size(); j++) {
            // search for either the person or the computer in a connection
            if(toLowerCase(connections[j].getPerson() -> getName()).find(search) != string::npos || toLowerCase(connections[j].getComputer() -> getName()).find(search) != string::npos) {
                out.push_back(&connections[j]);
            }
        }
    }
    return out;
}

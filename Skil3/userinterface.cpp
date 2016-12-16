#include "userinterface.h"

UserInterface::UserInterface() {
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    this -> manager = new EntityManager(tPtr -> tm_year + 1900); // parameter is the current year
}

EntityManager* UserInterface::getEntityManager() {
    return manager;
}

bool UserInterface::removeEntity(Entity *entity, QString s, int type) {
    QMessageBox rmBox;
    rmBox.setWindowTitle("Remove entity");
    rmBox.setText("Are you sure you want to remove "+s);
    rmBox.setStandardButtons(QMessageBox::Yes);
    rmBox.addButton(QMessageBox::No);
    rmBox.setDefaultButton(QMessageBox::No);
    if(rmBox.exec() == QMessageBox::Yes){
        return manager -> remove(entity, type);
    }
    return false;
}

Connection* UserInterface::getConnection(string person, string computer) {
    int pId = 0;
    int cId = 0;
    Person *p = NULL;
    Computer *c = NULL;
    vector<Entity*> persons = manager -> getEntities(PERSON);
    vector<Entity*> computers = manager -> getEntities(COMPUTER);
    for(unsigned int i = 0; i < persons.size(); i++) {
        if(persons[i] -> getName() == person) {
            pId = persons[i] -> getID();
            p = static_cast<Person*>(persons[i]);
            break;
        }
    }
    for(unsigned int i = 0; i < computers.size(); i++) {
        if(computers[i] -> getName() == computer) {
            cId = computers[i] -> getID();
            c = static_cast<Computer*>(computers[i]);
            break;
        }
    }
    Connection *connection = new Connection(pId, cId);
    connection -> setPerson(p);
    connection -> setComputer(c);
    return connection;
}

vector<Entity*> UserInterface::getEntities(int type) {
    return manager -> getEntities(type);
}

vector<Entity*> UserInterface::getSearchResults(string s, string filter, int type) {
    return manager -> getFilteredSearchResults(s, filter, type);
}

QStandardItemModel* UserInterface::getTableModel(vector<Entity*> entities, int type) {
    return manager -> getTableModel(entities, type);
}


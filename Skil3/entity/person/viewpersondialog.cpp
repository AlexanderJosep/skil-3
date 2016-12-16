#include "viewpersondialog.h"
#include "ui_viewpersondialog.h"

ViewPersonDialog::ViewPersonDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ViewPersonDialog) {
    ui -> setupUi(this);
    setWindowTitle("View Person");
    imageName = DEFULT_PERSON_IMAGE;
    ui -> connectionTableView -> setSelectionMode(QAbstractItemView::SingleSelection);
    ui -> connectionTableView -> horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch);
    QPixmap pixmap(QPixmap(imageName).scaled(450, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui -> imageLabel -> setPixmap(pixmap);
    ui -> imageLabel -> setFixedHeight(pixmap.height());
    ui -> imageLabel -> setFixedWidth(pixmap.width());
    layout() -> setSizeConstraint(QLayout::SetFixedSize);
}

ViewPersonDialog::~ViewPersonDialog() {
    delete ui;
}

void ViewPersonDialog::setEntityManager(EntityManager *manager) {
    this -> manager = manager;
    ui -> birthYearBox -> setMinimum(0);
    ui -> deathYearBox -> setMinimum(0);
}

void ViewPersonDialog::setPerson(Person *person) {
    this -> person = person;
    ui -> nameBox-> setText(QString::fromStdString(person -> getName()));
    ui -> genderBox -> setCurrentIndex(person -> getGender());
    ui -> birthYearBox -> setValue(person -> getBirthYear());
    if(person -> getDeathYear() >= 0) {
        ui -> personDeadBox -> setChecked(true);
        ui -> deathYearBox -> setValue(person -> getDeathYear());
    }
    int id = manager -> getID(person, PERSON);
    QString image = QString::fromStdString("./images/persons/"+to_string(id));
    if(QFile::exists(image)) {
        imageName = image;
        QPixmap pixmap(QPixmap(imageName).scaled(450, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        ui -> imageLabel -> setPixmap(pixmap);
    }
    vector<Connection*> personConnections;
    vector<Entity*> connections = manager -> getEntities(CONNECTION);
    for(unsigned int i = 0; i < connections.size(); i++) {
        Connection* connection = static_cast<Connection*>(connections[i]);
        if(connection -> getPersonID() == id) {
            personConnections.push_back(connection);
        }
    }
    QStandardItemModel *model = new QStandardItemModel(personConnections.size(), 1);
    model -> setHorizontalHeaderItem(0, new QStandardItem(QString("Connected to")));
    for(unsigned int i = 0; i < personConnections.size(); i++) {
        QStandardItem *row1 = new QStandardItem(QString::fromStdString(personConnections[i] -> getComputer() -> getName()));
        model -> setItem(i, 0, row1);
    }

    ui -> connectionTableView -> setModel(model);
}

void ViewPersonDialog::on_closeButton_clicked() {
    this -> close();
}

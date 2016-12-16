#include "viewcomputerdialog.h"
#include "ui_viewcomputerdialog.h"

ViewComputerDialog::ViewComputerDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ViewComputerDialog) {
    ui -> setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle("View Computer");
    imageName = DEFULT_COMPUTER_IMAGE;
    ui -> connectionTableView -> setSelectionMode(QAbstractItemView::SingleSelection);
    ui -> connectionTableView -> horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch);
    QPixmap pixmap(QPixmap(imageName).scaled(450, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui -> imageLabel -> setPixmap(pixmap);
    ui -> imageLabel -> setAlignment(Qt::AlignCenter);
    ui -> imageLabel -> setFixedHeight(pixmap.height());
    ui -> imageLabel -> setFixedWidth(pixmap.width());
    layout() -> setSizeConstraint(QLayout::SetFixedSize);
}

ViewComputerDialog::~ViewComputerDialog() {
    delete ui;
}

void ViewComputerDialog::setEntityManager(EntityManager *manager) {
    this -> manager = manager;
    ui -> buildYearBox  -> setMinimum(0);
    ui -> buildYearBox -> setMaximum(manager -> getCurrentYear());
}

void ViewComputerDialog::setComputer(Computer *computer) {
    this -> computer = computer;
    ui -> nameBox-> setText(QString::fromStdString(computer -> getName()));
    ui -> typeBox -> setCurrentIndex(computer -> getType());
    if(computer -> getYear() >= 0) {
        ui -> computerBuiltBox -> setChecked(true);
        ui -> buildYearBox -> setValue(computer -> getYear());
    }
    int id = manager -> getID(computer, COMPUTER);
    QString image = QString::fromStdString("./data/images/computers/"+to_string(id));
    if(QFile::exists(image)) {
        imageName = image;
        QPixmap pixmap(QPixmap(imageName).scaled(450, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui -> imageLabel -> setPixmap(pixmap);
        ui -> imageLabel -> setAlignment(Qt::AlignCenter);
    }
    vector<Connection*> personConnections;
    vector<Entity*> connections = manager -> getEntities(CONNECTION);
    for(unsigned int i = 0; i < connections.size(); i++) {
        Connection* connection = static_cast<Connection*>(connections[i]);
        if(connection -> getComputerID() == id) {
            personConnections.push_back(connection);
        }
    }
    QStandardItemModel *model = new QStandardItemModel(personConnections.size(), 1);
    model -> setHorizontalHeaderItem(0, new QStandardItem(QString("Connected to")));
    for(unsigned int i = 0; i < personConnections.size(); i++) {
        QStandardItem *row1 = new QStandardItem(QString::fromStdString(personConnections[i] -> getPerson() -> getName()));
        model -> setItem(i, 0, row1);
    }
    ui -> connectionTableView -> setModel(model);
}

void ViewComputerDialog::on_closeButtom_clicked() {
    this -> close();
}

#include "addpersondialog.h"
#include "ui_addpersondialog.h"

AddPersonDialog::AddPersonDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddPersonDialog) {
    ui -> setupUi(this);
    layout() -> setSizeConstraint(QLayout::SetFixedSize);
    setWindowTitle("Add Person");
    edit = false;
    imageName = DEFULT_PERSON_IMAGE;
    QPixmap pixmap(QPixmap(imageName).scaled(450, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui -> imageLabel -> setPixmap(pixmap);
    ui -> imageLabel -> setFixedHeight(pixmap.height());
    ui -> imageLabel -> setFixedWidth(pixmap.width());
    edit = false;
    updatedImage = false;
}

AddPersonDialog::~AddPersonDialog() {
    delete ui;
}

void AddPersonDialog::setEntityManager(EntityManager *manager) {
    this -> manager = manager;
    ui -> birthYearBox -> setMinimum(0);
    ui -> birthYearBox -> setMaximum(manager -> getCurrentYear());
    ui -> deathYearBox -> setMinimum(0);
    ui -> deathYearBox -> setMaximum(manager -> getCurrentYear());
}

void AddPersonDialog::setPerson(Person *person) {
    this -> person = person;
    this -> edit = true;
    setWindowTitle("Edit Person");
    ui -> addButton -> setText("Save");
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
}

void AddPersonDialog::on_personDeadBox_toggled(bool checked) {
    ui -> deathYearBox -> setEnabled(checked);
}

void AddPersonDialog::on_addButton_clicked() {
    string name = ui -> nameBox -> text().toStdString();
    name = manager -> trim(name);
    name = manager -> capitialize(name);
    if(!manager -> validName(name, 0)) {
        QMessageBox errorBox;
        errorBox.critical(0,"Error", "Please select a valid name!");
        errorBox.setFixedSize(500, 200);
        return;
    }
    short gender = ui -> genderBox -> currentIndex();
    short birthYear = ui -> birthYearBox -> value();
    short deathYear = ui -> personDeadBox -> isChecked() ? ui -> deathYearBox -> value() : -1;
    Person *person = new Person(name, gender, birthYear, deathYear);
    if(edit) {
        manager -> edit(this -> person, person, PERSON);
    } else {
        manager -> add(person, PERSON);
    }

    int id = manager -> getID(person, PERSON);
    if(imageName != DEFULT_PERSON_IMAGE && updatedImage) {
        QFile::remove(QString::fromStdString("./images/persons/"+to_string(id)));
        QFile::copy(imageName, QString::fromStdString("./images/persons/"+to_string(id)));
    } else if(imageName == DEFULT_PERSON_IMAGE) {
        QFile::remove(QString::fromStdString("./images/persons/"+to_string(id)));
    }
    this -> close();
}

void AddPersonDialog::on_cancelButton_clicked() {
    this -> close();
}

void AddPersonDialog::on_birthYearBox_valueChanged(int arg1) {
    ui -> deathYearBox -> setMinimum(arg1);
}

void AddPersonDialog::on_imageSelection_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Select an image"), QDir::currentPath(), tr("*.jpg *.jpeg *.png"));
    if(fileName != NULL) {
        imageName = fileName;
        QPixmap pixmap(QPixmap(imageName).scaled(450, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        ui -> imageLabel -> setPixmap(pixmap);
        updatedImage = true;
    }
}

void AddPersonDialog::on_removeImageButton_clicked() {
    imageName = DEFULT_PERSON_IMAGE;
    QPixmap pixmap(QPixmap(imageName).scaled(450, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui -> imageLabel -> setPixmap(pixmap);
}

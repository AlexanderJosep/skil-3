#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

AddComputerDialog::AddComputerDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddComputerDialog) {
    ui -> setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    layout() -> setSizeConstraint(QLayout::SetFixedSize);
    setWindowTitle("Add Computer");
    imageName = DEFULT_COMPUTER_IMAGE;
    QPixmap pixmap(QPixmap(imageName).scaled(450, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui -> imageLabel -> setPixmap(pixmap);
    ui -> imageLabel -> setAlignment(Qt::AlignCenter);
    ui -> imageLabel -> setFixedHeight(pixmap.height());
    ui -> imageLabel -> setFixedWidth(pixmap.width());
    edit = false;
    updatedImage = false;
}

AddComputerDialog::~AddComputerDialog() {
    delete ui;
}

void AddComputerDialog::setEntityManager(EntityManager *manager) {
    this -> manager = manager;
    ui -> buildYearBox  -> setMinimum(0);
    ui -> buildYearBox -> setMaximum(manager -> getCurrentYear());
}

void AddComputerDialog::setComputer(Computer *computer) {
    this -> computer = computer;
    this -> edit = true;
    setWindowTitle("Edit Computer");
    ui -> addButton -> setText("Save");
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
        ui -> imageLabel -> setAlignment(Qt::AlignCenter);
        ui -> imageLabel -> setPixmap(pixmap);
    }
}

void AddComputerDialog::on_cancelButton_clicked() {
    this -> close();
}

void AddComputerDialog::on_addButton_clicked() {
    string name = ui -> nameBox -> text().toStdString();
    name = manager -> trim(name);
    if(!manager -> validName(name, 1)) {
        QMessageBox errorBox;
        errorBox.critical(0,"Error", "Please select a valid name!");
        errorBox.setFixedSize(500, 200);
        return;
    }
    short type = ui -> typeBox -> currentIndex();
    short buildYear = ui -> computerBuiltBox -> isChecked() ? ui -> buildYearBox -> value() : -1;
    Computer *computer = new Computer(name, buildYear, type);
    if(edit) {
        manager -> edit(this -> computer, computer, COMPUTER);
    } else {
        manager -> add(computer, COMPUTER);
    }

    int id = manager -> getID(computer, COMPUTER);
    if(imageName != DEFULT_COMPUTER_IMAGE && updatedImage) {
        QFile::remove(QString::fromStdString("./data/images/computers/"+to_string(id)));
        QFile::copy(imageName, QString::fromStdString("./data/images/computers/"+to_string(id)));
    } else if(imageName == DEFULT_COMPUTER_IMAGE) {
        QFile::remove(QString::fromStdString("./data/images/computers/"+to_string(id)));
    }
    this -> close();
}

void AddComputerDialog::on_computerBuiltBox_toggled(bool checked) {
    ui -> buildYearBox -> setEnabled(checked);
}

void AddComputerDialog::on_imageSelection_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Select an image"), QDir::currentPath(), tr("*.jpg *.jpeg *.png"));
    if(fileName != NULL) {
        imageName = fileName;
        QPixmap pixmap(QPixmap(imageName).scaled(450, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        ui -> imageLabel -> setPixmap(pixmap);
        updatedImage = true;
    }
}

void AddComputerDialog::on_removeImageButton_clicked() {
    imageName = DEFULT_COMPUTER_IMAGE;
    QPixmap pixmap(QPixmap(imageName).scaled(450, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui -> imageLabel -> setPixmap(pixmap);
}

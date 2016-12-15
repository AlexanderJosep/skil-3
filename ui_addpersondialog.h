/********************************************************************************
** Form generated from reading UI file 'addpersondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPERSONDIALOG_H
#define UI_ADDPERSONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddPersonDialog
{
public:
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QCheckBox *personDeadBox;
    QLineEdit *nameBox;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *genderBox;
    QSpinBox *birthYearBox;
    QSpinBox *deathYearBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *AddPersonDialog)
    {
        if (AddPersonDialog->objectName().isEmpty())
            AddPersonDialog->setObjectName(QStringLiteral("AddPersonDialog"));
        AddPersonDialog->resize(243, 212);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddPersonDialog->sizePolicy().hasHeightForWidth());
        AddPersonDialog->setSizePolicy(sizePolicy);
        AddPersonDialog->setMinimumSize(QSize(0, 0));
        AddPersonDialog->setMaximumSize(QSize(174444, 174444));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddPersonDialog->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(AddPersonDialog);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(AddPersonDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(AddPersonDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        personDeadBox = new QCheckBox(AddPersonDialog);
        personDeadBox->setObjectName(QStringLiteral("personDeadBox"));

        gridLayout->addWidget(personDeadBox, 3, 3, 1, 1);

        nameBox = new QLineEdit(AddPersonDialog);
        nameBox->setObjectName(QStringLiteral("nameBox"));

        gridLayout->addWidget(nameBox, 0, 3, 1, 1);

        label_3 = new QLabel(AddPersonDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(AddPersonDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        genderBox = new QComboBox(AddPersonDialog);
        genderBox->setObjectName(QStringLiteral("genderBox"));

        gridLayout->addWidget(genderBox, 1, 3, 1, 1);

        birthYearBox = new QSpinBox(AddPersonDialog);
        birthYearBox->setObjectName(QStringLiteral("birthYearBox"));

        gridLayout->addWidget(birthYearBox, 2, 3, 1, 1);

        deathYearBox = new QSpinBox(AddPersonDialog);
        deathYearBox->setObjectName(QStringLiteral("deathYearBox"));
        deathYearBox->setEnabled(false);

        gridLayout->addWidget(deathYearBox, 4, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        addButton = new QPushButton(AddPersonDialog);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout_3->addWidget(addButton);

        cancelButton = new QPushButton(AddPersonDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);

        QWidget::setTabOrder(nameBox, genderBox);
        QWidget::setTabOrder(genderBox, birthYearBox);
        QWidget::setTabOrder(birthYearBox, personDeadBox);
        QWidget::setTabOrder(personDeadBox, deathYearBox);
        QWidget::setTabOrder(deathYearBox, addButton);
        QWidget::setTabOrder(addButton, cancelButton);

        retranslateUi(AddPersonDialog);

        QMetaObject::connectSlotsByName(AddPersonDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPersonDialog)
    {
        AddPersonDialog->setWindowTitle(QApplication::translate("AddPersonDialog", "Add", 0));
        label_2->setText(QApplication::translate("AddPersonDialog", "Gender:", 0));
        label->setText(QApplication::translate("AddPersonDialog", "Name:", 0));
        personDeadBox->setText(QApplication::translate("AddPersonDialog", "Person dead", 0));
        label_3->setText(QApplication::translate("AddPersonDialog", "Birth year:", 0));
        label_4->setText(QApplication::translate("AddPersonDialog", "Death year:", 0));
        genderBox->clear();
        genderBox->insertItems(0, QStringList()
         << QApplication::translate("AddPersonDialog", "Male", 0)
         << QApplication::translate("AddPersonDialog", "Female", 0)
        );
        addButton->setText(QApplication::translate("AddPersonDialog", "Add", 0));
        cancelButton->setText(QApplication::translate("AddPersonDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AddPersonDialog: public Ui_AddPersonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPERSONDIALOG_H

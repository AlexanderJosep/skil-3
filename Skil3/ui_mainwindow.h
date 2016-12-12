/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_6;
    QLineEdit *lineFilter;
    QLineEdit *lineSearch;
    QPushButton *pushButton_5;
    QPushButton *viewButton;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *removeButton;
    QComboBox *comboBox;
    QTableView *tableView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(359, 340);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 4, 1, 1);

        lineFilter = new QLineEdit(centralWidget);
        lineFilter->setObjectName(QStringLiteral("lineFilter"));

        gridLayout->addWidget(lineFilter, 2, 2, 1, 2);

        lineSearch = new QLineEdit(centralWidget);
        lineSearch->setObjectName(QStringLiteral("lineSearch"));

        gridLayout->addWidget(lineSearch, 0, 2, 1, 2);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 0, 4, 1, 1);

        viewButton = new QPushButton(centralWidget);
        viewButton->setObjectName(QStringLiteral("viewButton"));

        gridLayout->addWidget(viewButton, 8, 2, 1, 1);

        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        gridLayout->addWidget(addButton, 8, 3, 1, 1);

        editButton = new QPushButton(centralWidget);
        editButton->setObjectName(QStringLiteral("editButton"));

        gridLayout->addWidget(editButton, 8, 4, 1, 1);

        removeButton = new QPushButton(centralWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        gridLayout->addWidget(removeButton, 8, 5, 1, 1);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 2, 5, 1, 1);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);
        tableView->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tableView, 3, 2, 3, 4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 359, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Filter", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Search", 0));
        viewButton->setText(QApplication::translate("MainWindow", "View", 0));
        addButton->setText(QApplication::translate("MainWindow", "Add", 0));
        editButton->setText(QApplication::translate("MainWindow", "Edit", 0));
        removeButton->setText(QApplication::translate("MainWindow", "Remove", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Persons", 0)
         << QApplication::translate("MainWindow", "Computers", 0)
         << QApplication::translate("MainWindow", "Connections", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

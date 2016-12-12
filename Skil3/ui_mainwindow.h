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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineSearch;
    QTableView *tableViewPersons;
    QPushButton *pushButton_5;
    QPushButton *removePButton;
    QPushButton *addPButton;
    QPushButton *viewPButton;
    QPushButton *editPButton;
    QLineEdit *lineFilter;
    QPushButton *pushButton_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(661, 390);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineSearch = new QLineEdit(centralWidget);
        lineSearch->setObjectName(QStringLiteral("lineSearch"));

        gridLayout->addWidget(lineSearch, 0, 0, 1, 1);

        tableViewPersons = new QTableView(centralWidget);
        tableViewPersons->setObjectName(QStringLiteral("tableViewPersons"));
        tableViewPersons->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableViewPersons->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewPersons->setSortingEnabled(true);
        tableViewPersons->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tableViewPersons, 0, 2, 3, 4);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 0, 1, 1, 1);

        removePButton = new QPushButton(centralWidget);
        removePButton->setObjectName(QStringLiteral("removePButton"));

        gridLayout->addWidget(removePButton, 3, 4, 1, 1);

        addPButton = new QPushButton(centralWidget);
        addPButton->setObjectName(QStringLiteral("addPButton"));

        gridLayout->addWidget(addPButton, 3, 3, 1, 1);

        viewPButton = new QPushButton(centralWidget);
        viewPButton->setObjectName(QStringLiteral("viewPButton"));

        gridLayout->addWidget(viewPButton, 3, 2, 1, 1);

        editPButton = new QPushButton(centralWidget);
        editPButton->setObjectName(QStringLiteral("editPButton"));

        gridLayout->addWidget(editPButton, 3, 5, 1, 1);

        lineFilter = new QLineEdit(centralWidget);
        lineFilter->setObjectName(QStringLiteral("lineFilter"));

        gridLayout->addWidget(lineFilter, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 661, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Search", 0));
        removePButton->setText(QApplication::translate("MainWindow", "Remove", 0));
        addPButton->setText(QApplication::translate("MainWindow", "Add", 0));
        viewPButton->setText(QApplication::translate("MainWindow", "View", 0));
        editPButton->setText(QApplication::translate("MainWindow", "Edit", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Filter", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QRadioButton *radioButtonP1;
    QRadioButton *radioButtonP2;
    QRadioButton *radioButtonP3;
    QRadioButton *radioButtonP4;
    QLabel *label;
    QRadioButton *radioButtonP5;
    QPushButton *addPButton;
    QPushButton *removePButton;
    QPushButton *editPButton;
    QPushButton *viewPButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLineEdit *lineSearch;
    QLineEdit *lineFilter;
    QTableView *tableViewPersons;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(937, 326);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        radioButtonP1 = new QRadioButton(centralWidget);
        radioButtonP1->setObjectName(QStringLiteral("radioButtonP1"));
        radioButtonP1->setGeometry(QRect(20, 89, 91, 20));
        radioButtonP2 = new QRadioButton(centralWidget);
        radioButtonP2->setObjectName(QStringLiteral("radioButtonP2"));
        radioButtonP2->setGeometry(QRect(20, 109, 51, 21));
        radioButtonP3 = new QRadioButton(centralWidget);
        radioButtonP3->setObjectName(QStringLiteral("radioButtonP3"));
        radioButtonP3->setGeometry(QRect(20, 129, 61, 20));
        radioButtonP4 = new QRadioButton(centralWidget);
        radioButtonP4->setObjectName(QStringLiteral("radioButtonP4"));
        radioButtonP4->setGeometry(QRect(20, 149, 61, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 69, 51, 16));
        radioButtonP5 = new QRadioButton(centralWidget);
        radioButtonP5->setObjectName(QStringLiteral("radioButtonP5"));
        radioButtonP5->setEnabled(true);
        radioButtonP5->setGeometry(QRect(20, 169, 71, 20));
        radioButtonP5->setChecked(true);
        addPButton = new QPushButton(centralWidget);
        addPButton->setObjectName(QStringLiteral("addPButton"));
        addPButton->setGeometry(QRect(180, 199, 51, 20));
        removePButton = new QPushButton(centralWidget);
        removePButton->setObjectName(QStringLiteral("removePButton"));
        removePButton->setGeometry(QRect(240, 199, 51, 20));
        editPButton = new QPushButton(centralWidget);
        editPButton->setObjectName(QStringLiteral("editPButton"));
        editPButton->setGeometry(QRect(300, 199, 51, 20));
        viewPButton = new QPushButton(centralWidget);
        viewPButton->setObjectName(QStringLiteral("viewPButton"));
        viewPButton->setGeometry(QRect(120, 199, 51, 20));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(80, 9, 31, 20));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(80, 39, 31, 20));
        lineSearch = new QLineEdit(centralWidget);
        lineSearch->setObjectName(QStringLiteral("lineSearch"));
        lineSearch->setGeometry(QRect(10, 9, 61, 21));
        lineFilter = new QLineEdit(centralWidget);
        lineFilter->setObjectName(QStringLiteral("lineFilter"));
        lineFilter->setGeometry(QRect(10, 39, 61, 21));
        tableViewPersons = new QTableView(centralWidget);
        tableViewPersons->setObjectName(QStringLiteral("tableViewPersons"));
        tableViewPersons->setGeometry(QRect(120, 10, 231, 181));
        tableViewPersons->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableViewPersons->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewPersons->setSortingEnabled(true);
        tableViewPersons->verticalHeader()->setVisible(false);
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem13);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(410, 10, 511, 192));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);
        tableWidget->verticalHeader()->setVisible(false);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 937, 26));
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
        radioButtonP1->setText(QApplication::translate("MainWindow", "Name alphabetical", 0));
        radioButtonP2->setText(QApplication::translate("MainWindow", "Gender", 0));
        radioButtonP3->setText(QApplication::translate("MainWindow", "Birth year", 0));
        radioButtonP4->setText(QApplication::translate("MainWindow", "Death year", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Organizing</span></p></body></html>", 0));
        radioButtonP5->setText(QApplication::translate("MainWindow", "No organizing", 0));
        addPButton->setText(QApplication::translate("MainWindow", "Add", 0));
        removePButton->setText(QApplication::translate("MainWindow", "Remove", 0));
        editPButton->setText(QApplication::translate("MainWindow", "Edit", 0));
        viewPButton->setText(QApplication::translate("MainWindow", "View", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Search", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Filter", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Birth Year", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Gender", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Death Year", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "New Row", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "New Row", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Kristjan", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "1993", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 2);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "KK", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 3);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "NOPE", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(1, 0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Lubbi", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(1, 1);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "2003", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(1, 2);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "kk", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(1, 3);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "nope", 0));
        tableWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

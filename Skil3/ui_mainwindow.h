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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSnake;
    QAction *actionPong;
    QAction *actionSnake_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *editButton;
    QPushButton *viewButton;
    QGridLayout *gridLayout_2;
    QLabel *searchLabel;
    QLabel *label;
    QLineEdit *listFilter;
    QLineEdit *listSearch;
    QTableView *tableView;
    QComboBox *comboBox;
    QMenuBar *menuBar;
    QMenu *menuMain;
    QMenu *menuGames;
    QMenu *menuGames_2;
    QMenu *menuHiscores;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(421, 340);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/people_icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionSnake = new QAction(MainWindow);
        actionSnake->setObjectName(QStringLiteral("actionSnake"));
        actionPong = new QAction(MainWindow);
        actionPong->setObjectName(QStringLiteral("actionPong"));
        actionSnake_2 = new QAction(MainWindow);
        actionSnake_2->setObjectName(QStringLiteral("actionSnake_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(addButton, 12, 5, 1, 1);

        removeButton = new QPushButton(centralWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(removeButton, 12, 7, 1, 1);

        editButton = new QPushButton(centralWidget);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(editButton, 12, 6, 1, 1);

        viewButton = new QPushButton(centralWidget);
        viewButton->setObjectName(QStringLiteral("viewButton"));
        viewButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(viewButton, 12, 4, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        searchLabel = new QLabel(centralWidget);
        searchLabel->setObjectName(QStringLiteral("searchLabel"));
        searchLabel->setLayoutDirection(Qt::LeftToRight);
        searchLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        searchLabel->setWordWrap(false);

        gridLayout_2->addWidget(searchLabel, 0, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        listFilter = new QLineEdit(centralWidget);
        listFilter->setObjectName(QStringLiteral("listFilter"));

        gridLayout_2->addWidget(listFilter, 1, 2, 1, 1);

        listSearch = new QLineEdit(centralWidget);
        listSearch->setObjectName(QStringLiteral("listSearch"));

        gridLayout_2->addWidget(listSearch, 0, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 4, 1, 2);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);
        tableView->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tableView, 7, 4, 3, 4);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QFont font;
        font.setPointSize(10);
        comboBox->setFont(font);

        gridLayout->addWidget(comboBox, 0, 7, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 421, 19));
        menuMain = new QMenu(menuBar);
        menuMain->setObjectName(QStringLiteral("menuMain"));
        menuGames = new QMenu(menuMain);
        menuGames->setObjectName(QStringLiteral("menuGames"));
        menuGames_2 = new QMenu(menuBar);
        menuGames_2->setObjectName(QStringLiteral("menuGames_2"));
        menuHiscores = new QMenu(menuGames_2);
        menuHiscores->setObjectName(QStringLiteral("menuHiscores"));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(listSearch, listFilter);
        QWidget::setTabOrder(listFilter, comboBox);
        QWidget::setTabOrder(comboBox, viewButton);
        QWidget::setTabOrder(viewButton, addButton);
        QWidget::setTabOrder(addButton, editButton);
        QWidget::setTabOrder(editButton, removeButton);
        QWidget::setTabOrder(removeButton, tableView);

        menuBar->addAction(menuMain->menuAction());
        menuBar->addAction(menuGames_2->menuAction());
        menuMain->addSeparator();
        menuMain->addAction(menuGames->menuAction());
        menuGames_2->addAction(actionPong);
        menuGames_2->addAction(actionSnake);
        menuGames_2->addSeparator();
        menuGames_2->addAction(menuHiscores->menuAction());
        menuHiscores->addAction(actionSnake_2);

        retranslateUi(MainWindow);
        QObject::connect(actionSnake, SIGNAL(triggered()), MainWindow, SLOT(raise()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Main Window", 0));
        actionSnake->setText(QApplication::translate("MainWindow", "Snake", 0));
        actionPong->setText(QApplication::translate("MainWindow", "Pong", 0));
        actionSnake_2->setText(QApplication::translate("MainWindow", "Snake", 0));
#ifndef QT_NO_WHATSTHIS
        addButton->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>Add a entity..</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        addButton->setText(QApplication::translate("MainWindow", "Add", 0));
        removeButton->setText(QApplication::translate("MainWindow", "Remove", 0));
        editButton->setText(QApplication::translate("MainWindow", "Edit", 0));
        viewButton->setText(QApplication::translate("MainWindow", "View", 0));
        searchLabel->setText(QApplication::translate("MainWindow", "Search:", 0));
        label->setText(QApplication::translate("MainWindow", "Filter:", 0));
#ifndef QT_NO_WHATSTHIS
        listSearch->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>Search..</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Persons", 0)
         << QApplication::translate("MainWindow", "Computers", 0)
         << QApplication::translate("MainWindow", "Connections", 0)
        );
#ifndef QT_NO_WHATSTHIS
        comboBox->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>List types..</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        menuMain->setTitle(QApplication::translate("MainWindow", "Main", 0));
        menuGames->setTitle(QApplication::translate("MainWindow", "Games", 0));
        menuGames_2->setTitle(QApplication::translate("MainWindow", "Games", 0));
        menuHiscores->setTitle(QApplication::translate("MainWindow", "Hiscores", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

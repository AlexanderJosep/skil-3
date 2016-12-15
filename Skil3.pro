#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T09:35:04
#
#-------------------------------------------------

QT       += core sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Skil3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    entity/entity.cpp \
    entity/computer/computer.cpp \
    entity/connection/connection.cpp \
    entity/entitymanager.cpp \
    entity/person/person.cpp \
    snake/snake.cpp \
    snake/snakegrid.cpp \
    snake/snakescore.cpp \
    snake/snakethread.cpp \
    snake/snakewidget.cpp \
    console.cpp \
    storage/storage.cpp \
    userinterface.cpp \
    pong/pongwidget.cpp \
    pong/pong.cpp \
    pong/pongracket.cpp \
    pong/pongthread.cpp \
    pong/pongball.cpp \
    entity/person/addpersondialog.cpp

HEADERS  += mainwindow.h \
    entity/entity.h \
    entity/computer/computer.h \
    entity/connection/connection.h \
    entity/entitymanager.h \
    entity/person/person.h \
    snake/snake.h \
    snake/snakegrid.h \
    snake/snakescore.h \
    snake/snakethread.h \
    snake/snakewidget.h \
    console.h \
    storage/storage.h \
    config.h \
    userinterface.h \
    pong/pongwidget.h \
    pong/pong.h \
    pong/pongracket.h \
    pong/pongthread.h \
    pong/pongball.h \
    entity/person/addpersondialog.h

FORMS    += mainwindow.ui \
    entity/person/addpersondialog.ui

RESOURCES += \
    resources.qrc

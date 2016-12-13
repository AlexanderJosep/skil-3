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
    entity.cpp \
    computer.cpp \
    connection.cpp \
    entitymanager.cpp \
    person.cpp \
    snake.cpp \
    snakegrid.cpp \
    snakescore.cpp \
    snakethread.cpp \
    snakewidget.cpp \
    console.cpp \
    storage.cpp \
    userinterface.cpp \
    pongwidget.cpp \
    pong.cpp \
    pongracket.cpp \
    pongthread.cpp \
    pongball.cpp \
    addwindow.cpp

HEADERS  += mainwindow.h \
    entity.h \
    computer.h \
    connection.h \
    entitymanager.h \
    person.h \
    snake.h \
    snakegrid.h \
    snakescore.h \
    snakethread.h \
    snakewidget.h \
    console.h \
    storage.h \
    config.h \
    userinterface.h \
    pongwidget.h \
    pong.h \
    pongracket.h \
    pongthread.h \
    pongball.h \
    addwindow.h

FORMS    += mainwindow.ui \
    addwindow.ui

#-------------------------------------------------
#
# Project created by QtCreator 2015-03-14T02:30:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tower_Defence
TEMPLATE = app


SOURCES += main.cpp \
    tower.cpp \
    game.cpp \
    bullet.cpp \
    enemy.cpp

HEADERS  += \
    tower.h \
    game.h \
    bullet.h \
    enemy.h

RESOURCES += \
    res.qrc

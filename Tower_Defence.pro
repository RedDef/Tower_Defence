#-------------------------------------------------
#
# Project created by QtCreator 2015-03-14T02:30:02
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tower_Defence
TEMPLATE = app


SOURCES += main.cpp \
    tower.cpp \
    game.cpp \
    bullet.cpp \
    enemy.cpp \
    buildredtowericon.cpp \
    redtower.cpp \
    buildgreentowericon.cpp \
    greentower.cpp \
    buildbluetowericon.cpp \
    bluetower.cpp

HEADERS  += \
    tower.h \
    game.h \
    bullet.h \
    enemy.h \
    buildredtowericon.h \
    redtower.h \
    buildgreentowericon.h \
    greentower.h \
    buildbluetowericon.h \
    bluetower.h

RESOURCES += \
    res.qrc

DISTFILES += \
    Notes.txt

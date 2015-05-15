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
    bluetower.cpp \
    blacktower.cpp \
    buildblacktowericon.cpp \
    whitetower.cpp \
    buildwhitetowericon.cpp \
    yellowtower.cpp \
    buildyellowtowericon.cpp \
    gridpoint.cpp \
    health.cpp \
    score.cpp \
    enemy_point.cpp \
    road.cpp \

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
    bluetower.h \
    blacktower.h \
    buildblacktowericon.h \
    whitetower.h \
    buildwhitetowericon.h \
    yellowtower.h \
    buildyellowtowericon.h \
    gridpoint.h \
    health.h \
    score.h \
    enemy_point.h \
    road.h \

RESOURCES += \
    res.qrc

DISTFILES += \
    Notes.txt \
    desktop.ini \
    Tower_Defence.pro.user

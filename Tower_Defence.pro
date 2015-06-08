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
    area.cpp \
    blueenemy.cpp \
    enemy_list_element.cpp \
    greenenemy.cpp \
    money.cpp \
    orangeenemy.cpp \
    pausescreen.cpp \
    redenemy.cpp \
    violetenemy.cpp \
    yellowenemy.cpp \
    menu_background.cpp \
    menu_about.cpp \
    menu_go.cpp \
    menu_explain.cpp \
    aboutusscreen.cpp \
    explainscreen.cpp

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
    area.h \
    blueenemy.h \
    enemy_list_element.h \
    greenenemy.h \
    money.h \
    orangeenemy.h \
    pausescreen.h \
    redenemy.h \
    violetenemy.h \
    yellowenemy.h \
    menu_background.h \
    menu_about.h \
    menu_go.h \
    menu_explain.h \
    aboutusscreen.h \
    explainscreen.h

RESOURCES += \
    res.qrc

DISTFILES += \
    Notes.txt \
    desktop.ini \
    Tower_Defence.pro.user \
    button_go.png

FORMS +=

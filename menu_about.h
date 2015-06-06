#ifndef MENU_ABOUT
#define MENU_ABOUT

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsView>
#include "game.h"
#include "aboutusscreen.h"

class Menu_About: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Menu_About(QGraphicsItem *parent=0);//constructor
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    AboutusScreen *aboutus;

};

#endif // MENU_ABOUT


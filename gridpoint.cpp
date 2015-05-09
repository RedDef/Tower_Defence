#include "game.h"
#include "gridpoint.h"
#include <QPixmap>
#include <QPointF>
#include <QLineF>
#include <QGraphicsRectItem>
#include <QDebug>

extern Game *game;

Gridpoint::Gridpoint(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //set the graphics
    setPixmap(QPixmap(":/images/gridpoint.png"));
    occupied = false;

}


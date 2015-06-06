#include "menu_go.h"
#include <QDebug>

Menu_Go::Menu_Go(QGraphicsItem *parent){

    //set the graphics
    setPixmap(QPixmap(":/images/button_start.png"));

}

void Menu_Go::mousePressEvent(QGraphicsSceneMouseEvent *event){

    qDebug() << QString("clicked");

}


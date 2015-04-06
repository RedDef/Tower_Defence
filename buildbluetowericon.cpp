#include "buildbluetowericon.h"
#include "game.h"
#include "bluetower.h"

extern Game * game;

BuildBlueTowerIcon::BuildBlueTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/BlueTowerIcon.png"));
}

void BuildBlueTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->build){
        game->build = new BlueTower();
        game->setCursor(QString(":/images/bluetower.png"));
    }
}

#include "buildbluetowericon.h"
#include "game.h"
#include "bluetower.h"

extern Game * game;

BuildBlueTowerIcon::BuildBlueTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/tower_menu_blue.png"));
}

void BuildBlueTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->building){
        game->building = new BlueTower();
        game->setCursor(QString(":/images/tower_field_blue.png"));
    }
}

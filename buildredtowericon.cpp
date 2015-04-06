#include "buildredtowericon.h"
#include "game.h"
#include "redtower.h"

extern Game * game;

BuildRedTowerIcon::BuildRedTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/RedTowerIcon.png"));
}

void BuildRedTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->build){
        game->build = new RedTower();
        game->setCursor(QString(":/images/redtower.png"));
    }
}

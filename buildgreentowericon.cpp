#include "buildgreentowericon.h"
#include "game.h"
#include "greentower.h"

extern Game * game;

BuildGreenTowerIcon::BuildGreenTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/GreenTowerIcon.png"));
}

void BuildGreenTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->build){
        game->build = new GreenTower();
        game->setCursor(QString(":/images/greentower.png"));
    }
}

#include "buildgreentowericon.h"
#include "game.h"
#include "greentower.h"

extern Game * game;

BuildGreenTowerIcon::BuildGreenTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/tower_menu_green.png"));
}

void BuildGreenTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->building){
        game->building = new GreenTower();
        game->setCursor(QString(":/images/tower_field_green.png"));
    }
}

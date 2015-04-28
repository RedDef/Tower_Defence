#include "buildredtowericon.h"
#include "game.h"
#include "redtower.h"

extern Game * game;

BuildRedTowerIcon::BuildRedTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/tower_menu_red.png"));
}

void BuildRedTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->building){
        game->building = new RedTower();
        game->setCursor(QString(":/images/tower_field_red.png"));
    }
}

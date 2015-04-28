#include "buildyellowtowericon.h"
#include "game.h"
#include "yellowtower.h"

extern Game * game;

BuildYellowTowerIcon::BuildYellowTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/tower_menu_yellow.png"));
}

void BuildYellowTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->building){
        game->building = new YellowTower();
        game->setCursor(QString(":/images/tower_field_yellow.png"));
    }
}



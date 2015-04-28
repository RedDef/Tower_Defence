#include "buildwhitetowericon.h"
#include "game.h"
#include "whitetower.h"

extern Game * game;

BuildWhiteTowerIcon::BuildWhiteTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/tower_menu_white.png"));
}

void BuildWhiteTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->building){
        game->building = new WhiteTower();
        game->setCursor(QString(":/images/tower_field_white.png"));
    }
}


#include "buildblacktowericon.h"
#include "game.h"
#include "blacktower.h"

extern Game * game;

BuildBlackTowerIcon::BuildBlackTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/tower_menu_black.png"));

}

void BuildBlackTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->building){
        game->building = new BlackTower();
        game->setCursor(QString(":/images/tower_field_black.png"));

    }
}

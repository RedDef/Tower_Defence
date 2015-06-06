#include "buildblacktowericon.h"
#include "game.h"
#include "blacktower.h"

extern Game * game;

BuildBlackTowerIcon::BuildBlackTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/tower_menu_black.png"));
}

void BuildBlackTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){    
    if((!game->building)&&(game->global_timer->isActive())){
        game->building = new BlackTower();
        game->setCursor(QString(":/images/tower_field_black.png"));
        game->scene->addItem(game->building);

        QPoint p = game->mapFromGlobal(QCursor::pos());
        game->building->setPos(p.x()-18,p.y()-18);
        game->cursor->setPos(p.x()-18,p.y()-18);

        showText();
    }
}

void BuildBlackTowerIcon::setIcon(bool status)
{
    if(status!=old_icon){
        if(status==false){
            setPixmap(QPixmap(":/images/tower_menu_black_2.png"));
            old_icon=false;
        }
        else{
            setPixmap(QPixmap(":/images/tower_menu_black.png"));
            old_icon=true;
        }

    }
}

void BuildBlackTowerIcon::showText(){

    game->blackdamage->show();
    game->blackrange->show();
    game->blackspeed->show();

}

void BuildBlackTowerIcon::hideText(){

    game->blackdamage->hide();
    game->blackrange->hide();
    game->blackspeed->hide();

}

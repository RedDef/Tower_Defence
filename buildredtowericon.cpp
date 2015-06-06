#include "buildredtowericon.h"
#include "game.h"
#include "redtower.h"

extern Game * game;

BuildRedTowerIcon::BuildRedTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/tower_menu_red.png"));
}

void BuildRedTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if((!game->building)&&(game->global_timer->isActive())){
        game->building = new RedTower();
        game->setCursor(QString(":/images/tower_field_red.png"));
        game->scene->addItem(game->building);

        QPoint p = game->mapFromGlobal(QCursor::pos());
        game->building->setPos(p.x()-18,p.y()-18);
        game->cursor->setPos(p.x()-18,p.y()-18);

        showText();

    }
}

void BuildRedTowerIcon::setIcon(bool status)
{
    if(status!=old_icon){
        if(status==false){
            setPixmap(QPixmap(":/images/tower_menu_red_2.png"));
            old_icon=false;
        }
        else{
            setPixmap(QPixmap(":/images/tower_menu_red.png"));
            old_icon=true;
        }

    }
}

void BuildRedTowerIcon::showText(){

    game->reddamage->show();
    game->redrange->show();
    game->redspeed->show();

}

void BuildRedTowerIcon::hideText(){

    game->reddamage->hide();
    game->redrange->hide();
    game->redspeed->hide();

}

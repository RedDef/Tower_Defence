#include "buildbluetowericon.h"
#include "game.h"
#include "bluetower.h"

extern Game * game;

BuildBlueTowerIcon::BuildBlueTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/tower_menu_blue.png"));
}

void BuildBlueTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if((!game->building)&&(game->global_timer->isActive())){
        game->building = new BlueTower();
        game->setCursor(QString(":/images/tower_field_blue.png"));
        game->scene->addItem(game->building);

        QPoint p = game->mapFromGlobal(QCursor::pos());
        game->building->setPos(p.x()-18,p.y()-18);
        game->cursor->setPos(p.x()-18,p.y()-18);

        showText();
    }
}

void BuildBlueTowerIcon::setIcon(bool status)
{
    if(status!=old_icon){
        if(status==false){
            setPixmap(QPixmap(":/images/tower_menu_blue_2.png"));
            old_icon=false;
        }
        else{
            setPixmap(QPixmap(":/images/tower_menu_blue.png"));
            old_icon=true;
        }

    }
}

void BuildBlueTowerIcon::showText(){

    game->bluedamage->show();
    game->bluerange->show();
    game->bluespeed->show();

}

void BuildBlueTowerIcon::hideText(){

    game->bluedamage->hide();
    game->bluerange->hide();
    game->bluespeed->hide();

}

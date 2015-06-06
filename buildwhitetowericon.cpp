#include "buildwhitetowericon.h"
#include "game.h"
#include "whitetower.h"

extern Game * game;

BuildWhiteTowerIcon::BuildWhiteTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/tower_menu_white.png"));
}

void BuildWhiteTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if((!game->building)&&(game->global_timer->isActive())){
        game->building = new WhiteTower();
        game->setCursor(QString(":/images/tower_field_white.png"));
        game->scene->addItem(game->building);

        QPoint p = game->mapFromGlobal(QCursor::pos());
        game->building->setPos(p.x()-18,p.y()-18);
        game->cursor->setPos(p.x()-18,p.y()-18);

        showText();
    }
}

void BuildWhiteTowerIcon::setIcon(bool status)
{
    if(status!=old_icon){
        if(status==false){
            setPixmap(QPixmap(":/images/tower_menu_white_2.png"));
            old_icon=false;
        }
        else{
            setPixmap(QPixmap(":/images/tower_menu_white.png"));
            old_icon=true;
        }

    }
}

void BuildWhiteTowerIcon::showText(){

    game->whitedamage->show();
    game->whiterange->show();
    game->whitespeed->show();

}

void BuildWhiteTowerIcon::hideText(){

    game->whitedamage->hide();
    game->whiterange->hide();
    game->whitespeed->hide();

}


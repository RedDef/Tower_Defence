#include "buildgreentowericon.h"
#include "game.h"
#include "greentower.h"

extern Game * game;

BuildGreenTowerIcon::BuildGreenTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/tower_menu_green.png"));
}

void BuildGreenTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if((!game->building)&&(game->global_timer->isActive())){
        game->building = new GreenTower();
        game->setCursor(QString(":/images/tower_field_green.png"));
        game->scene->addItem(game->building);

        QPoint p = game->mapFromGlobal(QCursor::pos());
        game->building->setPos(p.x()-18,p.y()-18);
        game->cursor->setPos(p.x()-18,p.y()-18);

        showText();
    }
}

void BuildGreenTowerIcon::setIcon(bool status)
{
    if(status!=old_icon){
        if(status==false){
            setPixmap(QPixmap(":/images/tower_menu_green_2.png"));
            old_icon=false;
        }
        else{
            setPixmap(QPixmap(":/images/tower_menu_green.png"));
            old_icon=true;
        }

    }
}

void BuildGreenTowerIcon::showText(){

    game->greendamage->show();
    game->greenrange->show();
    game->greenspeed->show();

}

void BuildGreenTowerIcon::hideText(){

    game->greendamage->hide();
    game->greenrange->hide();
    game->greenspeed->hide();

}

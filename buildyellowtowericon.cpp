#include "buildyellowtowericon.h"
#include "game.h"
#include "yellowtower.h"

extern Game * game;

BuildYellowTowerIcon::BuildYellowTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/tower_menu_yellow.png"));
}

void BuildYellowTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if((!game->building)&&(game->global_timer->isActive())&&(!game->gameover)){
        buildTower();
        game->selectTower=6;
    }
}

void BuildYellowTowerIcon::setIcon(bool status)
{
    if(status!=old_icon){
        if(status==false){
            setPixmap(QPixmap(":/images/tower_menu_yellow_2.png"));
            old_icon=false;
        }
        else{
            setPixmap(QPixmap(":/images/tower_menu_yellow.png"));
            old_icon=true;
        }

    }
}

void BuildYellowTowerIcon::showText(){

    game->yellowdamage->show();
    game->yellowrange->show();
    game->yellowspeed->show();
}


void BuildYellowTowerIcon::hideText(){

    game->yellowdamage->hide();
    game->yellowrange->hide();
    game->yellowspeed->hide();

}

void BuildYellowTowerIcon::buildTower()
{
    game->building = new YellowTower();
    game->setCursor(QString(":/images/tower_field_yellow.png"));
    game->scene->addItem(game->building);

    QPoint p = game->mapFromGlobal(QCursor::pos());
    game->building->setPos(p.x()-18,p.y()-18);
    game->cursor->setPos(p.x()-18,p.y()-18);

    showText();
}



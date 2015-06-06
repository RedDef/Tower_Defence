#include "money.h"
#include <QFont>
#include "game.h"
#include "bluetower.h"
#include "blacktower.h"
#include "whitetower.h"
#include "yellowtower.h"
#include "greentower.h"
#include "redtower.h"

extern Game *game;

Money::Money(QGraphicsItem *parent): QGraphicsTextItem(parent){

    //initialize money -> initual value
    money = 100;

    // draw the text
    setPlainText(QString("Money: ") + QString::number(money)); // money: 0
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",16));

}

void Money::increase(int enemy_worth){
    money = money+enemy_worth;  // increase money for each kill
    setPlainText(QString("Money: ") + QString::number(money));
    setBuildIcons();

}

void Money::decrease(int tower_cost)
{
    money -= tower_cost;    // decrease money by building a tower
    setPlainText(QString("Money: ") + QString::number(money));
    setBuildIcons();
}

int Money::getMoney(){
    return money;
}

void Money::setBuildIcons()
{
    if(money>=game->costBlackTower){
        game->bkt->setIcon(true);
    }
    else{
        game->bkt->setIcon(false);
    }

    if(money>=game->costRedTower){
        game->rt->setIcon(true);
    }
    else{
        game->rt->setIcon(false);
    }

    if(money>=game->costGreenTower){
        game->gt->setIcon(true);
    }
    else{
        game->gt->setIcon(false);
    }

    if(money>=game->costBlueTower){
        game->bt->setIcon(true);
    }
    else{
        game->bt->setIcon(false);
    }

    if(money>=game->costWhiteTower){
        game->wt->setIcon(true);
    }
    else{
        game->wt->setIcon(false);
    }

    if(money>=game->costYellowTower){
        game->yt->setIcon(true);
    }
    else{
        game->yt->setIcon(false);
    }
}


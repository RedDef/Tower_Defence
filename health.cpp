#include "health.h"
#include <QFont>
#include "game.h"

extern Game *game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    //initialize health
    health = 20;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 20
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;

    if(health<0){
        game->gameover=true;

        game->focusedTower=nullptr;

        if(game->building){
            game->scene->removeItem(game->building);
            game->scene->removeItem(game->cursor);
            delete game->building;
            delete game->cursor;
            game->building=nullptr;
            game->cursor=nullptr;
            game->rt->hideText();
            game->gt->hideText();
            game->bt->hideText();
            game->yt->hideText();
            game->wt->hideText();
            game-> bkt->hideText();
        }

        game->createEnemisState=7;

        game->gameOverScreen =  new QGraphicsPixmapItem(QString(":/images/gameover2.png"));
        game->gameOverScreen->setPos(0,0);
        game->scene->addItem(game->gameOverScreen);

        game->finalScore  = new QGraphicsTextItem;
        game->finalScore->setPlainText(QString("Your final Score is: ") + QString::number(game->score->getScore()));
        game->finalScore ->setDefaultTextColor(Qt::red);
        game->finalScore ->setFont(QFont("times",30));
        game->finalScore ->setPos(250,370);
        game->scene->addItem(game->finalScore);

        game->scene->removeItem(game->startbutton);
        game->scene->addItem(game->startbutton);




    }
    else{
        setPlainText(QString("Health: ") + QString::number(health));
    }
}

int Health::getHealth(){
    return health;
}

void Health::setHealth(int newHealth)
{
    health=newHealth;
    setPlainText(QString("Health: ") + QString::number(health));
}


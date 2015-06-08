#include "menu_go.h"
#include <QDebug>
#include "game.h"

extern Game *game;
extern void restart();


Menu_Go::Menu_Go(QGraphicsItem *parent){

    //set the graphics
    setPixmap(QPixmap(":/images/button_start.png"));

}

void Menu_Go::mousePressEvent(QGraphicsSceneMouseEvent *event){

    qDebug() << QString("clicked");

    if(!game->global_timer->isActive()){

            if(game->gameover){

                game->global_timer->start(40);
                game->health->setHealth(20);
                game->score->setScore(0);
                game->money->setMoney(200);
                game->gameover=false;


                game->scene->removeItem(game->gameOverScreen);
                delete game->gameOverScreen;

                game->scene->removeItem(game->finalScore);
                delete game->finalScore;

            }
            else{
                game->global_timer->start(40);
            }
    }

    //game->RestartGame();
    //game->scene->clear();


 /*  Game* game_old = game;
   game=new Game();
   game->show();
   delete game_old;*/

}


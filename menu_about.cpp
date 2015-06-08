#include "menu_about.h"
#include "game.h"
#include "aboutusscreen.h"
#include <QDebug>

extern Game *game;

Menu_About::Menu_About(QGraphicsItem *parent){

    //set the graphics
    setPixmap(QPixmap(":/images/button_aboutus.png"));

}

void Menu_About::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if(game->global_timer->isActive()&&(!game->gameover)){
            game->global_timer->stop();
            aboutus = new AboutusScreen();
            game->scene->addItem(aboutus);
            aboutus->setPos(0,0);
            game->keyPressEnable = false;
    }

}

#include "aboutusscreen.h"
#include "game.h"
#include "menu_about.h"

extern Game *game;


AboutusScreen::AboutusScreen(QGraphicsItem *parent){

    setPixmap(QPixmap(":/images/AboutUs.png"));

}

void AboutusScreen::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if(game->global_timer->isActive()==0){

        game->global_timer->start();
        game->scene->removeItem(this);
        delete this;

        game->keyPressEnable = true;

    }
}

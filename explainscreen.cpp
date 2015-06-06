#include "explainscreen.h"
#include "game.h"
#include "menu_explain.h"

extern Game *game;


ExplainScreen::ExplainScreen(QGraphicsItem *parent){

    setPixmap(QPixmap(":/images/Manual.png"));

}

void ExplainScreen::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if(game->global_timer->isActive()==0){

        game->global_timer->start();
        game->scene->removeItem(this);
        delete this;

        game->keyPressEnable = true;

    }

}

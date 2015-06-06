#include "menu_explain.h"
#include "game.h"
#include "explainscreen.h"
#include <QDebug>

extern Game *game;

Menu_Explain::Menu_Explain(QGraphicsItem *parent){

    //set the graphics
    setPixmap(QPixmap(":/images/button_help.png"));

}

void Menu_Explain::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if(game->global_timer->isActive()){
            game->global_timer->stop();
            explain = new ExplainScreen();
            game->scene->addItem(explain);
            explain->setPos(0,0);
            game->keyPressEnable = false;
    }

}

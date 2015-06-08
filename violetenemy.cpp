#include "violetenemy.h"
#include "game.h"

extern Game * game;

VioletEnemy::VioletEnemy(QGraphicsItem *parent)
{
    //set graphics
    setPixmap(QPixmap(":/images/enemy3.png"));
    step_count=0;
    STEP_SIZE=10;
    health_enemy=12;
    game->enemy_list[enemy_nr].step_size=STEP_SIZE;
}


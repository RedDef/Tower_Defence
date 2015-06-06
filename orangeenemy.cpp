#include "orangeenemy.h"
#include "game.h"

extern Game * game;

OrangeEnemy::OrangeEnemy(QGraphicsItem *parent)
{
    //set graphics
    setPixmap(QPixmap(":/images/enemy4.png"));
    step_count=0;
    STEP_SIZE=5;
    health_enemy=10;
    game->enemy_list[enemy_nr].step_size=STEP_SIZE;
}



#include "redenemy.h"
#include "game.h"

extern Game * game;

RedEnemy::RedEnemy(QGraphicsItem *parent)
{
    //set graphics
    setPixmap(QPixmap(":/images/enemy5.png"));
    step_count=0;
    STEP_SIZE=5;
    health_enemy=30;
    game->enemy_list[enemy_nr].step_size=STEP_SIZE;
}



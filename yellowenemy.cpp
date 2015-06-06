#include "yellowenemy.h"
#include "game.h"

extern Game * game;


YellowEnemy::YellowEnemy(QGraphicsItem *parent)
{
    //set graphics
    setPixmap(QPixmap(":/images/enemy0.png"));
    step_count=0;
    STEP_SIZE=7;
    health_enemy=10;
    game->enemy_list[enemy_nr].step_size=STEP_SIZE;
}

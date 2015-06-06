#include "greenenemy.h"
#include "game.h"

extern Game * game;

GreenEnemy::GreenEnemy(QGraphicsItem *parent)
{
    //set graphics
    setPixmap(QPixmap(":/images/enemy1.png"));
    step_count=0;
    STEP_SIZE=4;
    health_enemy=10;
    game->enemy_list[enemy_nr].step_size=STEP_SIZE;
}




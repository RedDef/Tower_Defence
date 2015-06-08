#include "blueenemy.h"
#include "game.h"

extern Game * game;

BlueEnemy::BlueEnemy(QGraphicsItem *parent)
{
    //set graphics
    setPixmap(QPixmap(":/images/enemy2.png"));
    step_count=0;
    STEP_SIZE=4;
    health_enemy=10;
    game->enemy_list[enemy_nr].step_size=STEP_SIZE;
}


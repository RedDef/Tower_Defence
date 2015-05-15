#ifndef ENEMY_POINT_H
#define ENEMY_POINT_H
#include <QPointF>
#include "enemy.h"

class enemy_point
{
public:
    enemy_point();
    QPointF position_enemy;//position of the enemy_point
    int step_size=0; //step_size of the enemy
    Enemy * enemy = nullptr; //pointer to the enemy which is here
};

#endif // ENEMY_POINT_H

#ifndef ENEMY_POINT_H
#define ENEMY_POINT_H
#include <QPointF>
#include "enemy.h"

class enemy_point{

public:
    enemy_point();//constructor

    /*position of the enemy_point:
      if an enemy moves to this point in the way_points[] array,
      he copies this cordinates*/
    QPointF position_enemy;

    /*step_size of the enemy;
      if an enemy reaches this point, he passes his step size to this point;
      the tower uses this variable in the aquire target function to callculate the flight path of the bullet*/
    int step_size=0;

    /*pointer-adress of the enemy;
      if an enemy reaches this point, he passes his pointer-adress to this point;
      the bullet uses this adress in the hit function to know which enemy to hit*/
    Enemy * enemy = nullptr;

};

#endif // ENEMY_POINT_H

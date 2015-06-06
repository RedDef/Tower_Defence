#ifndef ENEMY_LIST_ELEMENT_H
#define ENEMY_LIST_ELEMENT_H
#include <QPointF>
#include "enemy.h"

class enemy_list_element{

public:
    enemy_list_element();//constructor

    int step=(-1);

    QPointF position= QPointF(0,0);

    /*step_size of the enemy;
      if an enemy reaches this point, he passes his step size to this point;
      the tower uses this variable in the aquire target function to callculate the flight path of the bullet*/
    int step_size=0;

    /*pointer-adress of the enemy;
      if an enemy reaches this point, he passes his pointer-adress to this point;
      the bullet uses this adress in the hit function to know which enemy to hit*/
    Enemy * pointer = nullptr;

};

#endif // ENEMY_LIST_ELEMENT_H

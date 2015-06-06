#ifndef BLUEENEMY_H
#define BLUEENEMY_H

#include "enemy.h"


class BlueEnemy: public Enemy{
    Q_OBJECT
public:
    BlueEnemy(QGraphicsItem *parent = 0);//constructor
};

#endif // BLUEENEMY_H

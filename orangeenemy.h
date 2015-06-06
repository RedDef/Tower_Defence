#ifndef ORANGEENEMY_H
#define ORANGEENEMY_H


#include "enemy.h"


class OrangeEnemy: public Enemy{
    Q_OBJECT
public:
    OrangeEnemy(QGraphicsItem *parent = 0);//constructor
};

#endif // ORANGEENEMY_H

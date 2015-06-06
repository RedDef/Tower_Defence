#ifndef REDENEMY_H
#define REDENEMY_H


#include "enemy.h"


class RedEnemy: public Enemy{
    Q_OBJECT
public:
    RedEnemy(QGraphicsItem *parent = 0);//constructor
};

#endif // REDENEMY_H

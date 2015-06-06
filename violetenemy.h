#ifndef VIOLETENEMY_H
#define VIOLETENEMY_H


#include "enemy.h"


class VioletEnemy: public Enemy{
    Q_OBJECT
public:
    VioletEnemy(QGraphicsItem *parent = 0);//constructor
};

#endif // VIOLETENEMY_H

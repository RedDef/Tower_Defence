#ifndef GREENENEMY_H
#define GREENENEMY_H
#include "enemy.h"


class GreenEnemy: public Enemy{
    Q_OBJECT
public:
    GreenEnemy(QGraphicsItem *parent = 0);//constructor
};


#endif // GREENENEMY_H

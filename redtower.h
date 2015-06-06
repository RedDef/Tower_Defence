#ifndef REDTOWER
#define REDTOWER

#include "tower.h"

class RedTower: public Tower{
    Q_OBJECT

public:
    RedTower(QGraphicsItem *parent = 0);//constructor
    void fire();//function to fire bullets

public slots:
    void aquired_target();//checks if a enemy is in his range

};

#endif // REDTOWER


#ifndef YELLOWTOWER
#define YELLOWTOWER

#include "tower.h"

class YellowTower: public Tower{
    Q_OBJECT

public:
    YellowTower(QGraphicsItem *parent = 0);//constructor
    void fire();//function to fire bullets

public slots:
    void aquired_target();//checks if a enemy is in his range

};

#endif // YELLOWTOWER


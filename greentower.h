#ifndef GREENTOWER
#define GREENTOWER

#include "tower.h"

class GreenTower: public Tower{
    Q_OBJECT

public:
    GreenTower(QGraphicsItem *parent = 0);//constructor
    void fire();//function to fire bullets

public slots:
    void aquired_target();//checks if a enemy is in his range

};

#endif // GREENTOWER


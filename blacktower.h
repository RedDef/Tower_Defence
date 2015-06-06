#ifndef BLACKTOWER
#define BLACKTOWER

#include "tower.h"

class BlackTower: public Tower{
    Q_OBJECT

public:
    BlackTower(QGraphicsItem *parent = 0);//constructor
    void fire();//function to fire bullets

public slots:
    void aquired_target();//checks if a enemy is in his range

};

#endif // BLACKTOWER


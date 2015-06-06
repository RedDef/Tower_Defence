#ifndef BLUETOWER
#define BLUETOWER

#include "tower.h"

class BlueTower: public Tower{
    Q_OBJECT

public:
    BlueTower(QGraphicsItem *parent = 0);//constructor
    void fire();//function to fire bullets

public slots:
    void aquired_target();//checks if a enemy is in his range

};


#endif // BLUETOWER


#ifndef WHITETOWER
#define WHITETOWER

#include "tower.h"

class WhiteTower: public Tower{
    Q_OBJECT

public:
    WhiteTower(QGraphicsItem *parent = 0);//constructor
    void fire();//function to fire bullets

public slots:
    void aquired_target();//checks if a enemy is in his range

};

#endif // WHITETOWER


#ifndef YELLOWTOWER
#define YELLOWTOWER

#include "tower.h"

class YellowTower: public Tower{
    Q_OBJECT
public:
    YellowTower(QGraphicsItem *parent = 0);
    void fire();
public slots:
    void aquired_target();
};

#endif // YELLOWTOWER


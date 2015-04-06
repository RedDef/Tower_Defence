#ifndef REDTOWER
#define REDTOWER

#include "tower.h"

class RedTower: public Tower{
    Q_OBJECT
public:
    RedTower(QGraphicsItem *parent = 0);
    void fire();
public slots:
    void aquired_target();
};

#endif // REDTOWER


#ifndef GREENTOWER
#define GREENTOWER

#include "tower.h"

class GreenTower: public Tower{
    Q_OBJECT
public:
    GreenTower(QGraphicsItem *parent = 0);
    void fire();
public slots:
    void aquired_target();
};

#endif // GREENTOWER


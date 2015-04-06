#ifndef BLUETOWER
#define BLUETOWER

#include "tower.h"

class BlueTower: public Tower{
    Q_OBJECT
public:
    BlueTower(QGraphicsItem *parent = 0);
    void fire();
public slots:
    void aquired_target();
};


#endif // BLUETOWER


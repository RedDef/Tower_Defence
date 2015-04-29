#ifndef BLACKTOWER
#define BLACKTOWER

#include "tower.h"

class BlackTower: public Tower{
    Q_OBJECT
public:
    BlackTower(QGraphicsItem *parent = 0);
    void fire();
public slots:
    void aquired_target();
};

#endif // BLACKTOWER
//silly test

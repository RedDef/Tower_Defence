#ifndef WHITETOWER
#define WHITETOWER

#include "tower.h"

class WhiteTower: public Tower{
    Q_OBJECT
public:
    WhiteTower(QGraphicsItem *parent = 0);
    void fire();
public slots:
    void aquired_target();
};

#endif // WHITETOWER


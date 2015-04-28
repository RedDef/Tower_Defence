#include "yellowtower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>

extern Game * game;

YellowTower::YellowTower(QGraphicsItem *parent){
    //connect a timer to attack_target
 shoot_speed=5;
}

void YellowTower::fire(){
    Bullet *bullet = new Bullet();
    bullet->setPixmap(QPixmap(":/images/arrow_yellow.png"));
    bullet->setPos(x()+18, y()+18);

    QLineF ln(QPointF(x()+18,y()+18),attack_dest);
    int angle = -1 * ln.angle(); //*(-1) for clockwise rotation

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void YellowTower::aquired_target(){
    Tower::aquire_target();
}

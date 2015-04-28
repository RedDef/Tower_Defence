#include "bluetower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>

extern Game * game;

BlueTower::BlueTower(QGraphicsItem *parent){
    //connect a timer to attack_target
shoot_speed=20;
}

void BlueTower::fire(){
    Bullet *bullet = new Bullet();
    bullet->setPixmap(QPixmap(":/images/arrow_blue.png"));
    bullet->setPos(x()+10, y()+10);

    QLineF ln(QPointF(x()+12,y()+12),attack_dest);
    int angle = -1 * ln.angle(); //*(-1) for clockwise rotation

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void BlueTower::aquired_target(){
    Tower::aquire_target();
}

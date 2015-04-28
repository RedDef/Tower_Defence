#include "blacktower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>

extern Game * game;

BlackTower::BlackTower(QGraphicsItem *parent){
    //connect a timer to attack_target
shoot_speed=25;

}

void BlackTower::fire(){
    Bullet *bullet = new Bullet();
    bullet->setPixmap(QPixmap(":/images/arrow_black.png"));
    bullet->setPos(x()+10, y()+10);

    QLineF ln(QPointF(x()+12,y()+12),attack_dest);
    int angle = -1 * ln.angle(); //*(-1) for clockwise rotation

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void BlackTower::aquired_target(){
    Tower::aquire_target();
}


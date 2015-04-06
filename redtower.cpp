#include "redtower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>

extern Game * game;

RedTower::RedTower(QGraphicsItem *parent){
    //connect a timer to attack_target
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
}

void RedTower::fire(){
    Bullet *bullet = new Bullet();
    bullet->setPixmap(QPixmap(":/images/redarrow.png"));
    bullet->setPos(x()+10, y()+10);

    QLineF ln(QPointF(x()+12,y()+12),attack_dest);
    int angle = -1 * ln.angle(); //*(-1) for clockwise rotation

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void RedTower::aquired_target(){
    Tower::aquire_target();
}

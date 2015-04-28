#include "greentower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>

extern Game * game;

GreenTower::GreenTower(QGraphicsItem *parent){
    //connect a timer to attack_target
shoot_speed=15;
}

void GreenTower::fire(){
    //create the bullets
    Bullet *bullet1 = new Bullet();
    Bullet *bullet2 = new Bullet();
    Bullet *bullet3 = new Bullet();

    //set the graphics
    bullet1->setPixmap(QPixmap(":/images/arrow_green.png"));
    bullet2->setPixmap(QPixmap(":/images/arrow_green.png"));
    bullet3->setPixmap(QPixmap(":/images/arrow_green.png"));

    //set position
    bullet1->setPos(x()+18, y()+18);
    bullet2->setPos(x()+18, y()+18);
    bullet3->setPos(x()+18, y()+18);

    QLineF ln(QPointF(x()+18,y()+18),attack_dest);
    int angle = -1 * ln.angle(); //*(-1) for clockwise rotation

    //set angle
    bullet1->setRotation(angle);
    bullet2->setRotation(angle+10);
    bullet3->setRotation(angle-10);

    //add to scene
    game->scene->addItem(bullet1);
    game->scene->addItem(bullet2);
    game->scene->addItem(bullet3);
}

void GreenTower::aquired_target(){
    Tower::aquire_target();
}


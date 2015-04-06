#include "greentower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>

extern Game * game;

GreenTower::GreenTower(QGraphicsItem *parent){
    //connect a timer to attack_target
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
}

void GreenTower::fire(){
    //create the bullets
    Bullet *bullet1 = new Bullet();
    Bullet *bullet2 = new Bullet();
    Bullet *bullet3 = new Bullet();

    //set the graphics
    bullet1->setPixmap(QPixmap(":/images/greenarrow.png"));
    bullet2->setPixmap(QPixmap(":/images/greenarrow.png"));
    bullet3->setPixmap(QPixmap(":/images/greenarrow.png"));

    //set position
    bullet1->setPos(x()+10, y()+10);
    bullet2->setPos(x()+10, y()+10);
    bullet3->setPos(x()+10, y()+10);

    QLineF ln(QPointF(x()+12,y()+12),attack_dest);
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


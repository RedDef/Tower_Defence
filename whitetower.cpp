#include "whitetower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>

extern Game * game;

WhiteTower::WhiteTower(QGraphicsItem *parent){
    //connect a timer to attack_target
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(2000);
}

void WhiteTower::fire(){
    //create the bullets
    Bullet *bullet1 = new Bullet();
    Bullet *bullet2 = new Bullet();
    Bullet *bullet3 = new Bullet();
    Bullet *bullet4 = new Bullet();
    Bullet *bullet5 = new Bullet();

    //set the graphics
    bullet1->setPixmap(QPixmap(":/images/arrow_black.png"));
    bullet2->setPixmap(QPixmap(":/images/arrow_blue.png"));
    bullet3->setPixmap(QPixmap(":/images/arrow_green.png"));
    bullet4->setPixmap(QPixmap(":/images/arrow_red.png"));
    bullet5->setPixmap(QPixmap(":/images/arrow_yellow.png"));

    //set position
    bullet1->setPos(x()+18, y()+18);
    bullet2->setPos(x()+18, y()+18);
    bullet3->setPos(x()+18, y()+18);
    bullet4->setPos(x()+18, y()+18);
    bullet5->setPos(x()+18, y()+18);

    QLineF ln(QPointF(x()+18,y()+18),attack_dest);
    int angle = -1 * ln.angle(); //*(-1) for clockwise rotation

    //set angle
    bullet1->setRotation(angle);
    bullet2->setRotation(angle+72);
    bullet3->setRotation(angle+220);
    bullet4->setRotation(angle-72);
    bullet5->setRotation(angle+144);

    //add to scene
    game->scene->addItem(bullet1);
    game->scene->addItem(bullet2);
    game->scene->addItem(bullet3);
    game->scene->addItem(bullet4);
    game->scene->addItem(bullet5);

}

void WhiteTower::aquired_target(){
    Tower::aquire_target();
}


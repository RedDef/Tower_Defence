#include "greentower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>
#include <math.h>


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
    bullet1->setPos(x()+10, y()+10);
    bullet2->setPos(x()+10, y()+10);
    bullet3->setPos(x()+10, y()+10);

    QLineF ln(QPointF(x()+18,y()+18),attack_dest);
    int angle = -1 * ln.angle(); //*(-1) for clockwise rotation

    //set angle
    bullet1->dx=cos(angle*3.1415/180)*bullet1->STEP_SIZE;
    bullet1->dy=sin(angle*3.1415/180)*bullet1->STEP_SIZE;

    bullet2->dx=cos((angle+10)*3.1415/180)*bullet1->STEP_SIZE;
    bullet2->dy=sin((angle+10)*3.1415/180)*bullet1->STEP_SIZE;

    bullet3->dx=cos((angle-10)*3.1415/180)*bullet1->STEP_SIZE;
    bullet3->dy=sin((angle-10)*3.1415/180)*bullet1->STEP_SIZE;

    bullet1->steps_to_target=i;
    bullet2->steps_to_target=i;
    bullet3->steps_to_target=i;


    //add to scene
    game->scene->addItem(bullet1);
    game->scene->addItem(bullet2);
    game->scene->addItem(bullet3);
}

void GreenTower::aquired_target(){
    Tower::aquire_target();
}


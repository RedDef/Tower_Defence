#include "greentower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>
#include <math.h>


extern Game * game;

GreenTower::GreenTower(QGraphicsItem *parent){

    damage=5;
    shoot_speed=15;
    SCALE_FACTOR=100;
    setrange();
    tower_cost = 100; //costs of tower to build
    setPixmap(QPixmap(":/images/tower_field_green.png"));
}

void GreenTower::fire(){   

    /*Middle tower = size of tower/2 = 36/2 = 18
      Middle bullet = size of bullet/2 = 15/2 = 8*/

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

    bullet1->steps_to_target=steps_to_target; //passes steps_to_target from tower to bullet
    bullet2->steps_to_target=steps_to_target; //passes steps_to_target from tower to bullet
    bullet3->steps_to_target=steps_to_target; //passes steps_to_target from tower to bullet

    //add to scene
    game->scene->addItem(bullet1);
    game->scene->addItem(bullet2);
    game->scene->addItem(bullet3);
}

void GreenTower::aquired_target(){
    Tower::aquire_target();
}


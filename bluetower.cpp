#include "bluetower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>

extern Game * game;

BlueTower::BlueTower(QGraphicsItem *parent){

    shoot_speed=10;
    damage=1;
    SCALE_FACTOR=100;
    setrange();
    tower_cost = 100; //costs of tower to build
    setPixmap(QPixmap(":/images/tower_field_blue.png"));

}

void BlueTower::fire(){       

    /*Middle tower = size of tower/2 = 36/2 = 18
      Middle bullet = size of bullet/2 = 15/2 = 8*/

    Bullet *bullet = new Bullet();
    bullet->setPixmap(QPixmap(":/images/arrow_blue.png"));
    bullet->setPos(x()+10, y()+10);//+10 --> sets postion of the bullet to the middle of the tower
    bullet->steps_to_target=steps_to_target; //passes steps_to_target from tower to bullet
    bullet->damage_bullet=damage;//passes towerdamage to bullet

    /*callculates the direction of the bullet;
      temp includes delta(x) and delta(y);*/
    QPointF temp;
    temp = (QPointF(x()+18,y()+18)-(attack_dest));

    /*callculates by trigonometrie the angle to shoot;
      sqrt couldn't be zero, because tower couldn't be placed on path*/
    bullet->dx = -(bullet->STEP_SIZE)*temp.x()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));
    bullet->dy = -(bullet->STEP_SIZE)*temp.y()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));

    game->scene->addItem(bullet);
}

void BlueTower::aquired_target(){
    Tower::aquire_target();
}

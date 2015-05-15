#include "yellowtower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>

extern Game * game;

YellowTower::YellowTower(QGraphicsItem *parent){
    //connect a timer to attack_target
 shoot_speed=5;
 damage=1;
 SCALE_FACTOR=50;
}

void YellowTower::fire(){
    Bullet *bullet = new Bullet();
    bullet->setPixmap(QPixmap(":/images/arrow_yellow.png"));
    bullet->setPos(x()+10, y()+10);
    bullet->steps_to_target=i;
    bullet->damage_bullet=1;

    QPointF temp;
    temp =(QPointF(x()+18,y()+18)-(attack_dest));

    bullet->dx = -(bullet->STEP_SIZE)*temp.x()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));
    bullet->dy = -(bullet->STEP_SIZE)*temp.y()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));

    game->scene->addItem(bullet);
}

void YellowTower::aquired_target(){
    Tower::aquire_target();
}

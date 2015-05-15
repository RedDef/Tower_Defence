#include "blacktower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>

extern Game * game;

BlackTower::BlackTower(QGraphicsItem *parent){
    //connect a timer to attack_target
shoot_speed=50;
damage=500;
SCALE_FACTOR=100;

}

void BlackTower::fire(){
    Bullet *bullet = new Bullet();
    bullet->setPixmap(QPixmap(":/images/arrow_black.png"));
    bullet->setPos(x()+10, y()+10);
    bullet->steps_to_target=i;
    bullet->damage_bullet=damage;
    QPointF temp;
    temp =(QPointF(x()+18,y()+18)-(attack_dest));

    bullet->dx = -(bullet->STEP_SIZE)*temp.x()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));
    bullet->dy = -(bullet->STEP_SIZE)*temp.y()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));

    game->scene->addItem(bullet);
}

void BlackTower::aquired_target(){
    Tower::aquire_target();
}


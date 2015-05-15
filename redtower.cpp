#include "redtower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>
#include <QPointF>

extern Game * game;

RedTower::RedTower(QGraphicsItem *parent){
    shoot_speed=1;
    damage=1;


}

void RedTower::fire(){

   Bullet *bullet = new Bullet();
    bullet->setPos(x()+10, y()+10);
    bullet->setPixmap(QPixmap(":/images/arrow_red.png"));
    bullet->steps_to_target=i;
    bullet->damage_bullet=damage;

    QPointF temp;
    temp =(QPointF(x()+18,y()+18)-(attack_dest));

    bullet->dx = -(bullet->STEP_SIZE)*temp.x()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));
    bullet->dy = -(bullet->STEP_SIZE)*temp.y()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));

    game->scene->addItem(bullet);

}

void RedTower::aquired_target(){
    Tower::aquire_target();
}

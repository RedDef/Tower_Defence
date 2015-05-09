#include "redtower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>
#include <QPointF>

extern Game * game;

RedTower::RedTower(QGraphicsItem *parent){
    //connect a timer to attack_target
    shoot_speed=10;
}

void RedTower::fire(){

    Bullet *bullet = new Bullet();
    bullet->setPos(x()+10, y()+10);
    bullet->setPixmap(QPixmap(":/images/arrow_red.png"));

    QPointF temp;
    double test;
    temp =(QPointF(x()+18,y()+18)-(attack_dest));

    bullet->dx = -(bullet->STEP_SIZE)*temp.x()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));
    bullet->dy = -(bullet->STEP_SIZE)*temp.y()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));

    game->scene->addItem(bullet);



    /*   Bullet *bullet = new Bullet();


    bullet->setPos(x()+18, y()+18);

    QLineF ln(QPointF(x()+18,y()+18),attack_dest);
   // int angle = -1 * ln.angle(); //*(-1) for clockwise rotation

//    bullet->setRotation(angle);
    game->scene->addItem(bullet);*/
}

void RedTower::aquired_target(){
    Tower::aquire_target();
}

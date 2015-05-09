#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include "score.h"
#include "health.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h> //math-functions for angles
#include <typeinfo>

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent){

    //connect a timer to move()
    connect(game->move_timer,SIGNAL(timeout()),this,SLOT(move()));

    //initialize values
    maxRange = 100;
    distanceTravalled = 0;
    damage_bullet=1;
    STEP_SIZE = 5;
    dx=0;
    dy=0;

}

void Bullet::move(){

    setPos(x()+dx, y()+dy);

    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    if((x()>720)||(x()<-5)||(y()>720)||(y()<-5)){
        scene()->removeItem(this);
        delete this;
    }

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            scene()->removeItem(this);
            Enemy *temp_enemy = dynamic_cast<Enemy *>(colliding_items[i]);
            temp_enemy->hit(damage_bullet);

            // delete them from the heap to save memory
            delete this;

            // return (all code below refers to a non existent bullet)
            return;
        }
    }

}

#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include "score.h"
#include "health.h"
#include <QPixmap>
#include <QTimer>
#include <typeinfo>

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent){

    //connect a timer to move()
    connect(game->global_timer,SIGNAL(timeout()),this,SLOT(move()));

    //initialize values
    distanceTravalled = 0;
    damage_bullet=1;
    STEP_SIZE = 7;
    dx=0;
    dy=0;


}

void Bullet::move(){

    double dif=1000;
    QPointF point_dif;

    distanceTravalled++;
    setPos(x()+dx,y()+dy);

    if((x()>705)||(x()<15)||(y()>705)||(y()<15)){ //if the bullet is out of the screen delete it
        scene()->removeItem(this);
        delete this;
        return;
    }

    if(distanceTravalled>steps_to_target){ // destroys bullet if it has traveled to far
        scene()->removeItem(this);
        delete this;
        return;
    }


    for(int counter=0;counter<=game->last_enemy;counter++){ //checks if it is colliding with an enemy
        if(game->enemy_list[counter].step!=(-1)){
            point_dif=(QPointF(x()+7,y()+7)-(game->enemy_list[counter].position));
            dif=(sqrt(pow(point_dif.x(),2)+pow(point_dif.y(),2))); //distance to enemy
            if(dif<=20){ // does the enemy touch the bullet?   25 = 18(tower diameter/2) +7 (bullet diameter/2)
                game->enemy_list[counter].pointer->hit(damage_bullet); // tells the enemy that he got hit
                scene()->removeItem(this);
                delete this;
                return;
            }

        }

    }


}


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


    // get a list of all the items currently colliding with this bullet


    if((x()>720)||(x()<-5)||(y()>720)||(y()<-5)){ //if the bullet is out of the screen delete it
        scene()->removeItem(this);
        delete this;
        return;
    }

    if(distanceTravalled>steps_to_target){ // destroys bullet if it has traveled to far
        scene()->removeItem(this);
        delete this;
        return;
    }


    for(int counter=0;counter<=game->last_enemy;counter++){ //checks if its colliding with an enemy
        if(game->enemy_list[counter]!=(-1)){
            point_dif=(QPointF(x()+7,y()+7)-(game->way_points[(game->enemy_list[counter])].position_enemy));
            dif=(sqrt(pow(point_dif.x(),2)+pow(point_dif.y(),2))); //distance to enemy
            if(dif<25){ // does the enemy touch the bullet?   25= 18(tower diameter/2) +7 (bullet diameter/2)

                game->way_points[game->enemy_list[counter]].enemy->hit(damage_bullet); // tells the enemy that he got hit
                scene()->removeItem(this);
                delete this;
                return;
            }

        }

    }


}


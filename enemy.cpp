#include "enemy.h"
#include "game.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>


extern Game * game;

Enemy::Enemy(QGraphicsItem *parent){

    //set graphics
    setPixmap(QPixmap(":/images/enemy0.png"));
    step_count=0;
    STEP_SIZE=2;
    health_enemy=500;
    enemy_worth = 10;

    //connect timer to move_foreward
    connect(game->global_timer,SIGNAL(timeout()),this,SLOT(move_foreward()));

    for(enemy_nr=0;game->enemy_list[enemy_nr].step!=(-1);enemy_nr++){} //finds the first free slot in the enemy_list

    if(enemy_nr>game->last_enemy){  //checks if it is the last enemy in the list
        game->last_enemy=enemy_nr; // set the new last enemy to his number
    }

    game->enemy_list[enemy_nr].step=0;//set its position in the enemy_list
    game->enemy_list[enemy_nr].pointer=this;
    game->enemy_list[enemy_nr].position=game->way_points[0];

}


void Enemy::hit(double damage){

    health_enemy = health_enemy - damage; //decreases the health of the enemy

    if (health_enemy <= 0){  
        game->enemy_list[enemy_nr].step=(-1);//clear all elements in way_points[] and enemy_list[]
        game->enemy_list[enemy_nr].step_size=0;
        game->enemy_list[enemy_nr].pointer=nullptr;
        game->enemy_list[enemy_nr].position=QPointF(0,0);

        if(enemy_nr==game->last_enemy){
            for(;(game->enemy_list[game->last_enemy].step==(-1))&&(game->last_enemy>0);){
                game->last_enemy--;
            }
        }

        game->score->increase(); // increase the game score
        game->money->increase(enemy_worth); //increase money

        //delete them from the heap to save memory
        scene()->removeItem(this);
        delete this;
        return;

    }
}

void Enemy::move_foreward(){// moves the enemy forward

    if(game->gameover){
        game->enemy_list[enemy_nr].step=(-1);
        game->enemy_list[enemy_nr].step_size=0;
        game->enemy_list[enemy_nr].pointer=nullptr;
        game->enemy_list[enemy_nr].position=QPointF(0,0);


        if(enemy_nr==game->last_enemy){
            for(;(game->enemy_list[game->last_enemy].step==(-1))&&(game->last_enemy>0);){
                game->last_enemy--;
            }
        }

        scene()->removeItem(this);
        delete this;
        return;
    }

    step_count+=STEP_SIZE; // goes to the next position

    if(step_count>=game->last_waypoint){ //if he has reached the last point destroy enemy and decrease the health of the game
        game->health->decrease();
        game->enemy_list[enemy_nr].step=(-1);
        game->enemy_list[enemy_nr].step_size=0;
        game->enemy_list[enemy_nr].pointer=nullptr;
        game->enemy_list[enemy_nr].position=QPointF(0,0);


        if(enemy_nr==game->last_enemy){
            for(;(game->enemy_list[game->last_enemy].step==(-1))&&(game->last_enemy>0);){
                game->last_enemy--;
            }
        }

        scene()->removeItem(this);
        delete this;
        return;
    }


    game->enemy_list[enemy_nr].step=step_count;
    game->enemy_list[enemy_nr].position=game->way_points[step_count];

    setPos(game->way_points[step_count]);//set new position
    setPos(x()-18, y()-18);//18 -> middle of the tower

}

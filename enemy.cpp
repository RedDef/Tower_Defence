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


    for(enemy_nr=0;game->enemy_list[enemy_nr]!=(-1);enemy_nr++){ //finds the first free slot in the enemy_list

    }
    if(enemy_nr>game->last_enemy){  //checks if he is the last enemy in the list
        game->last_enemy=enemy_nr; // set the new last enemy to his number
    }
    game->enemy_list[enemy_nr]=0;//set his position in the enemy_list

    //connect timer to move_foreward
    connect(game->move_timer,SIGNAL(timeout()),this,SLOT(move_foreward()));
}


void Enemy::hit(double damage){
    health_enemy = health_enemy - damage; //decreases the health of the enemy

    if (health_enemy <= 0) {
        game->way_points[step_count].step_size=0;   //clear all elements int way_points and enemy list
        game->way_points[step_count].enemy=nullptr;
        game->enemy_list[enemy_nr]=(-1);
        if(enemy_nr==game->last_enemy){
            game->last_enemy=(enemy_nr-1);
        }

        // increase Score
        game->score->increase(); // increase the game score

        // delete them from the heap to save memory
        scene()->removeItem(this);
        delete this;
        return;

    }
}

void Enemy::move_foreward(){// moves the enemy forward
    game->way_points[step_count].step_size=0; //clears old position
    game->way_points[step_count].enemy=nullptr;
    step_count+=STEP_SIZE; // goes to the next position
    if(step_count>=game->last_waypoint){ //if he has reached the last point destroy enemy and decrease the health of the game
        game->health->decrease();
        game->enemy_list[enemy_nr]=(-1);
        if(enemy_nr==game->last_enemy){
            game->last_enemy=(enemy_nr-1);
        }
        scene()->removeItem(this);
        delete this;
        return;
    }

    game->way_points[step_count].step_size=STEP_SIZE; //set all information on the new position
    game->enemy_list[enemy_nr]=step_count;
    game->way_points[step_count].enemy=this;

    setPos(game->way_points[step_count].position_enemy);//set new position
    setPos(x()-18, y()-18);

}

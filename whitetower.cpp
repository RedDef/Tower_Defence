#include "whitetower.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>

extern Game * game;

WhiteTower::WhiteTower(QGraphicsItem *parent){

    shoot_speed=15;
    damage=30;
    SCALE_FACTOR=80;
    setrange();
    tower_cost = 1500; //costs of tower to build
    setPixmap(QPixmap(":/images/tower_field_white.png"));

}

void WhiteTower::fire(){

    /*Middle tower = size of tower/2 = 36/2 = 18
      Middle bullet = size of bullet/2 = 15/2 = 8*/

    //create the bullets
    Bullet *bullet1 = new Bullet();
    Bullet *bullet2 = new Bullet();
    Bullet *bullet3 = new Bullet();
    Bullet *bullet4 = new Bullet();
    Bullet *bullet5 = new Bullet();
    Bullet *bullet6 = new Bullet();

    //set the graphics
    bullet1->setPixmap(QPixmap(":/images/arrow_black.png"));
    bullet2->setPixmap(QPixmap(":/images/arrow_blue.png"));
    bullet3->setPixmap(QPixmap(":/images/arrow_green.png"));
    bullet4->setPixmap(QPixmap(":/images/arrow_red.png"));
    bullet5->setPixmap(QPixmap(":/images/arrow_yellow.png"));
    bullet6->setPixmap(QPixmap(":/images/arrow_green.png"));

    //set position
    bullet1->setPos(x()+10, y()+10);
    bullet2->setPos(x()+10, y()+10);
    bullet3->setPos(x()+10, y()+10);
    bullet4->setPos(x()+10, y()+10);
    bullet5->setPos(x()+10, y()+10);
    bullet6->setPos(x()+10, y()+10);

    bullet1->dx=0.866*bullet1->STEP_SIZE;//values --> dx = sin(p); dy = cos(p); p={0°,60°,120°,180°,240°,300°)
    bullet1->dy=0.5*bullet1->STEP_SIZE;
    bullet2->dx=0*bullet2->STEP_SIZE;
    bullet2->dy=1*bullet2->STEP_SIZE;
    bullet3->dx=-0.866*bullet3->STEP_SIZE;
    bullet3->dy=0.5*bullet3->STEP_SIZE;
    bullet4->dx=-0.866*bullet4->STEP_SIZE;
    bullet4->dy=-0.5*bullet4->STEP_SIZE;
    bullet5->dx=0*bullet5->STEP_SIZE;
    bullet5->dy=-1*bullet5->STEP_SIZE;
    bullet6->dx=0.866*bullet6->STEP_SIZE;
    bullet6->dy=-0.5*bullet6->STEP_SIZE;

    bullet1->steps_to_target = SCALE_FACTOR/bullet1->STEP_SIZE;
    bullet2->steps_to_target = SCALE_FACTOR/bullet2->STEP_SIZE;
    bullet3->steps_to_target = SCALE_FACTOR/bullet3->STEP_SIZE;
    bullet4->steps_to_target = SCALE_FACTOR/bullet4->STEP_SIZE;
    bullet5->steps_to_target = SCALE_FACTOR/bullet5->STEP_SIZE;
    bullet6->steps_to_target = SCALE_FACTOR/bullet6->STEP_SIZE;

    bullet1->damage_bullet=damage;
    bullet2->damage_bullet=damage;;
    bullet3->damage_bullet=damage;;
    bullet4->damage_bullet=damage;;
    bullet5->damage_bullet=damage;;
    bullet6->damage_bullet=damage;;

    game->scene->addItem(bullet1);
    game->scene->addItem(bullet2);
    game->scene->addItem(bullet3);
    game->scene->addItem(bullet4);
    game->scene->addItem(bullet5);
    game->scene->addItem(bullet6);

}

void WhiteTower::aquired_target(){

    int n=range[0][0];
    int min=range[0][1];

      if(shoot_wait==0){

          has_target=false;

          for(int count=0;count<=(game->last_enemy+1);count++){//check if enemy is in range

              for(int test_range=0;test_range<=range_number;test_range++){
                  n=range[test_range][0];
                  min=range[test_range][1];

                  if((n>=game->enemy_list[count].step)&&(game->enemy_list[count].step>=min)){
                      fire();
                      shoot_wait++;
                      return;
                  }
               }
          }
      }

      else{
          shoot_wait++;

          if(shoot_wait>=shoot_speed){
              shoot_wait=0;
          }
      }
}


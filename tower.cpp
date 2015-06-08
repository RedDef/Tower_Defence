#include "tower.h"
#include "bullet.h"
#include "game.h"
#include "enemy.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QLineF>
#include <QPolygonF>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QDebug>
#include <qmath.h>


extern Game *game; 

void Tower::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if((game->global_timer->isActive())){
        attack_area->show();
        game->focusedTower=this;
    }
}

Tower::Tower(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    connect(game->global_timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    TowersGridpoint=nullptr;


    range[0][0]=9999;
    range[0][1]=9999;
    range[1][0]=9999;
    range[1][1]=9999;
    range[2][0]=9999;
    range[2][1]=9999;
    range[3][0]=9999;
    range[3][1]=9999;
    range[4][0]=9999;
    range[4][1]=9999;
    range[5][0]=9999;
    range[5][1]=9999;
    range[6][0]=9999;
    range[6][1]=9999;
    range[7][0]=9999;
    range[7][1]=9999;



}




void Tower::fire(){
    Bullet *bullet = new Bullet();
    bullet->setPos(x()+18, y()+18);

    QPointF temp;
    temp =(QPointF(x()+18,y())-(attack_dest));

    bullet->dx = -(bullet->STEP_SIZE)*temp.x()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));
    bullet->dx = -(bullet->STEP_SIZE)*temp.y()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));

    game->scene->addItem(bullet);

}

void Tower::find_targetpoints()
{
    QPointF point_dif;
    double dif;
    range_number=0;


    bool found_targetpoint=false;

    int n=game->last_waypoint;

    while(n>0){
        found_targetpoint=false;
        for(;(n>=0);n--){
            point_dif=(QPointF(x()+18,y()+18)-game->way_points[n]);
            dif=(sqrt(pow(point_dif.x(),2)+pow(point_dif.y(),2)));
            dif = (dif - 18-SCALE_FACTOR);


            if(dif<=0){
                found_targetpoint=true;
                break;
            }
        }
        if(found_targetpoint){
            range[range_number][0]=n;
            for(;(n>=0);n--){
                point_dif=(QPointF(x()+18,y()+18)-game->way_points[n]);
                dif=(sqrt(pow(point_dif.x(),2)+pow(point_dif.y(),2)));
                dif = (dif - 18-SCALE_FACTOR);
                if(dif>0){
                    break;
                }
            }
            range[range_number][1]=n;
        }
        else{
            return;
        }
        range_number++;
        }
    return;
}

void Tower::setrange()
{

    //create points vector --> circle
    QVector<QPointF> points;
    points << QPointF(0,1)<< QPointF(0.173648178,0.984807753)<< QPointF(0.342020143,0.939692621)<< QPointF(0.5,0.866025404)
           << QPointF(0.64278761,0.766044443)<< QPointF(0.766044443,0.64278761)<< QPointF(0.866025404,0.5)<< QPointF(0.939692621,0.342020143)
           << QPointF(0.984807753,0.173648178)<< QPointF(1,6.12574E-17)<< QPointF(0.984807753,-0.173648178)
           << QPointF(0.939692621,-0.342020143)<< QPointF(0.866025404,-0.5)<< QPointF(0.766044443,-0.64278761)
           << QPointF(0.64278761,-0.766044443)<< QPointF(0.5,-0.866025404)<< QPointF(0.342020143,-0.939692621)
           << QPointF(0.173648178,-0.984807753)<< QPointF(1.22515E-16,-1)<< QPointF(-0.173648178,-0.984807753)
           << QPointF(-0.342020143,-0.939692621)<< QPointF(-0.5,-0.866025404)
           << QPointF(-0.64278761,-0.766044443)<< QPointF(-0.766044443,-0.64278761)<< QPointF(-0.866025404,-0.5)
           << QPointF(-0.939692621,-0.342020143)<< QPointF(-0.984807753,-0.173648178)<< QPointF(-1,-1.83772E-16)
           << QPointF(-0.984807753,0.173648178)<< QPointF(-0.939692621,0.342020143)<< QPointF(-0.866025404,0.5)
           << QPointF(-0.766044443,0.64278761)<< QPointF(-0.64278761,0.766044443)<< QPointF(-0.5,0.866025404)
           << QPointF(-0.342020143,0.939692621) << QPointF(-0.173648178,0.984807753);


    //scale points
    for(size_t i =0, n=points.size(); i<n; i++){
        points[i] = points[i] * SCALE_FACTOR;
    }

    //create QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
    QPen *pen =new QPen;
    pen->setColor(Qt::red);
    pen->setStyle(Qt::DotLine);
    pen->setWidth(2);
    attack_area->setPen(*pen);


    //move the polygon
    QPointF poly_center(0,0);
    poly_center =mapToScene(poly_center);
    QPointF tower_center(x()+18,y()+18);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    //attack_area->hide();

}



void Tower::aquire_target(){

    if(game->gameover){
        TowersGridpoint->occupied=false;//gridpoint again free for new tower
        game->scene->removeItem(this);
        delete this;
        return;
    }


      int step_size=0;
      QPointF point_dif;
      int max=range[0][0];
      int min=range[0][1];
      int furthest_enemy=(-1);
      int furthest_enemy_nr=0;
      int countEnemisInRange=0;
      int test_counter=0;

    if(shoot_wait==0){

        has_target=false;

        for(int count=0;count<=(game->last_enemy+1);count++){

            for(int test_range=0;test_range<=range_number;test_range++){
                max=range[test_range][0];
                min=range[test_range][1];


                if((max>=game->enemy_list[count].step)&&(game->enemy_list[count].step>=min)){
                    HittableEnemys[countEnemisInRange]=count;
                    countEnemisInRange++;

                    if(game->enemy_list[count].step>furthest_enemy){
                        furthest_enemy=game->enemy_list[count].step;
                        furthest_enemy_nr=(countEnemisInRange-1);
                        step_size=game->enemy_list[count].step_size;
                        attack_dest=game->enemy_list[count].position;
                    }
                    break;
                }
             }
        }
        if(furthest_enemy>=0){
            test_counter=0;
            has_target=true;
            double dif=999;
            double dif_old=1000;
            for(steps_to_target=0;(dif>18);steps_to_target++){
                if((furthest_enemy+step_size*steps_to_target>game->last_waypoint)/*||(dif_old>dif)*/){
                   has_target=false;
                   HittableEnemys[furthest_enemy_nr]=-1;
                   break;
                }
                dif_old=dif;
                point_dif=(QPointF(x()+18,y()+18)-attack_dest);
                dif=(sqrt(pow(point_dif.x(),2)+pow(point_dif.y(),2)));
                dif = (dif - (steps_to_target*15));
                test_counter++;
                if(dif>30){
                   steps_to_target=steps_to_target+(dif/(15+step_size));
                   steps_to_target--;

                }

                attack_dest=game->way_points[(furthest_enemy+step_size*steps_to_target)];
            }
        }
        else{
            return;  //if no enemy in range stop the function (saves a lot of cpu ressources
        }


        if(has_target){
            fire();
            shoot_wait++;
            has_target=false;
        }
        else{

            for(int counter=0;(has_target==false)&&(counter<countEnemisInRange);counter++){
                furthest_enemy=(-1);
                furthest_enemy_nr=0;

                for(int count=0;count<countEnemisInRange;count++){
                    if(HittableEnemys[count]!=(-1)){
                        if(game->enemy_list[HittableEnemys[count]].step>furthest_enemy){
                            furthest_enemy=game->enemy_list[HittableEnemys[count]].step;
                            step_size=game->enemy_list[HittableEnemys[count]].step_size;
                            attack_dest=game->enemy_list[HittableEnemys[count]].position;
                            furthest_enemy_nr=count;
                        }

                    }
                }

                if(furthest_enemy>=0){
                    has_target=true;
                    double dif=999;
                    double dif_old=1000;
                    for(steps_to_target=0;(dif>18)/*&&(dif_old>dif)*/;steps_to_target++){
                        if(furthest_enemy+step_size*steps_to_target>game->last_waypoint){
                            has_target=false;
                            HittableEnemys[furthest_enemy_nr]=(-1);
                            break;

                        }
                        dif_old=dif;
                        point_dif=(QPointF(x()+18,y()+18)-attack_dest);
                        dif=(sqrt(pow(point_dif.x(),2)+pow(point_dif.y(),2)));
                        dif = (dif - (steps_to_target*15));
                        if(dif>30){
                           steps_to_target=steps_to_target+(dif/(15+step_size));
                           steps_to_target--;

                        }
                        attack_dest=game->way_points[(furthest_enemy+step_size*steps_to_target)];
                    }

                 }
                else{
                    break;
                }
            }

            if(has_target){
                fire();
                shoot_wait++;
                has_target = false;

            }else{
                return;
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

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

Tower::Tower(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    connect(game->move_timer,SIGNAL(timeout()),this,SLOT(aquire_target()));



    //create points vector
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
    attack_area->setPen(QPen(Qt::DotLine));

    //move the polygon
    QPointF poly_center(0,0);
    poly_center = poly_center * SCALE_FACTOR;
    poly_center =mapToScene(poly_center);
    QPointF tower_center(x()+18,y()+18);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());


 //   attack_area->hide();



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
            point_dif=(QPointF(x()+18,y()+18)-game->way_points[n].position_enemy);
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
                point_dif=(QPointF(x()+18,y()+18)-game->way_points[n].position_enemy);
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



void Tower::aquire_target(){
  double step_size=0;
  QPointF point_dif;
  int max=range[0][0];
  int min=range[0][1];
  int furthest_enemy=(-1);
  has_target=false;

    if(shoot_wait==0){

        has_target=false;

        for(int count=0;count<=(game->last_enemy+1);count++){

            for(int test_range=0;test_range<=range_number;test_range++){
                max=range[test_range][0];
                min=range[test_range][1];


                if((max>=game->enemy_list[count])&&(game->enemy_list[count]>=min)){
                    if(game->enemy_list[count]>furthest_enemy){
                        furthest_enemy=game->enemy_list[count];
                    }
                    break;
                }
             }
        }
        if(furthest_enemy>=0){
            has_target=true;
            step_size=game->way_points[furthest_enemy].step_size;
            attack_dest=game->way_points[furthest_enemy].position_enemy;
        }

        //just fire on targets, not on towers
        if(has_target){
            double dif=999;
            double dif_old=1000;
            for(i=0;(dif>12)&&(dif_old>dif)&&(furthest_enemy+step_size*i<game->last_waypoint);i++){
                dif_old=dif;
                point_dif=(QPointF(x()+18,y()+18)-attack_dest);
                dif=(sqrt(pow(point_dif.x(),2)+pow(point_dif.y(),2)));
                dif = (dif - (i*7));
                attack_dest=game->way_points[(furthest_enemy+game->way_points[furthest_enemy].step_size*i)].position_enemy;
            }
            fire();
            shoot_wait++;
        }else{
            return;
        }

        has_target = false;
    }
    else{
        shoot_wait++;
        if(shoot_wait>=shoot_speed){
            shoot_wait=0;
        }
    }

}

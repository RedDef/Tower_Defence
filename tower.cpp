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

    //ste the graphics
    //setPixmap(QPixmap(":/images/redtower.png"));

       way_points=game->pointsToFollow;
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
    int SCALE_FACTOR = 100;
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

    //set attack_dest
    attack_dest = QPointF(800,0);


}




double Tower::distanceTo(QGraphicsItem *item){
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Tower::fire(){
    Bullet *bullet = new Bullet();
    bullet->setPos(x()+18, y()+18);

    QLineF ln(QPointF(x()+18,y()+18),attack_dest);
    int angle = -1 * ln.angle(); //*(-1) for clockwise rotation

   // bullet->setRotation(angle);
    game->scene->addItem(bullet);

}

void Tower::aquire_target(){
  double max_step = 0;
  double dx=0;
  double dy=0;
  double step_size=0;

if(shoot_wait==0){

    //get a list of all items colliding with attack_area
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

    if(colliding_items.size() == 1){
        has_target = false;
        return;
    }



    QPointF target_pt = QPointF(0,0);
    for(size_t i = 0, n = colliding_items.size(); i < n; i++){
        Enemy *enemy = dynamic_cast<Enemy *>(colliding_items[i]);
        if(enemy){
            double this_step = enemy->step_count;
            if(this_step > max_step){
                max_step = this_step;
                target_pt =enemy->pos();
                dx=enemy->dx;
                dy=enemy->dy;
                step_size= enemy->STEP_SIZE;
                point_index= enemy->point_index;
                has_target = true;
            }
        }
    }
double test;
QLineF ln2;
QLineF ln;

    //just fire on targets, not on towers
    if(has_target){
        double dif=999;
        double dif_old=1000;
        for(int i=0;(dif>2)&&(dif_old>dif);i++){
            dif_old=dif;

            ln.setPoints(QPointF(x(),y()),target_pt);
            dif= (ln.length()-(i*5));


            if(point_index<(way_points.length()-1)){
                QPointF target_real_pos=target_pt;
                target_real_pos.setX(target_real_pos.x()+18);
                target_real_pos.setY(target_real_pos.y()+18);
                ln2.setPoints((way_points[point_index]),target_real_pos);
                test =ln2.length();
                if((test<step_size)){
                    target_pt=(way_points[point_index]);
                    target_pt.setX(target_pt.x()-18);
                    target_pt.setY(target_pt.y()-18);
                    dx=step_size*(game->direction[point_index][0]);
                    dy=step_size*(game->direction[point_index][1]);
                    point_index++;
                }
            }
            target_pt.setX(target_pt.rx()+dx);
            target_pt.setY(target_pt.ry()+dy);

        }
        target_pt.setX(target_pt.rx()+18);
        target_pt.setY(target_pt.ry()+18);
        attack_dest = target_pt;
        fire();
        shoot_wait++;
    }else{
        return;
    }

    has_target = false;

    qDebug() << "has_target " << has_target;
}
else{
    shoot_wait++;
    if(shoot_wait==shoot_speed){
        shoot_wait=0;
    }
}

}

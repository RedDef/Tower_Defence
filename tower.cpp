#include "tower.h"
#include "bullet.h"
#include "game.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QLineF>
#include <QPolygonF>
#include <QTimer>
#include <QGraphicsRectItem>

extern Game *game;

Tower::Tower(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //ste the graphics
    setPixmap(QPixmap(":/images/tower.png"));

    //create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1)
           << QPoint(3,2) << QPoint(2,3) << QPoint(1,3)
           << QPoint(0,2) << QPoint(0,1);

    //scale points
    int SCALE_FACTOR = 100;
    for(size_t i =0, n=points.size(); i<n; i++){
        points[i] = points[i] * SCALE_FACTOR;
    }

    //create a polygon from these points
    QPolygonF polygon(points);

    //create QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(polygon,this);

    //move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center = poly_center * SCALE_FACTOR;
    poly_center =mapToScene(poly_center);
    QPointF tower_center(x()+12,y()+12);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    //connect a timer to attack_target
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(attack_target()));
    timer->start(1000);

    //set attack_dest
    attack_dest = QPointF(800,800);

}

void Tower::attack_target(){
    Bullet *bullet = new Bullet();
    bullet->setPos(x()+10, y()+10);

    QLineF ln(QPointF(x()+12,y()+12),attack_dest);
    int angle = -1 * ln.angle(); //*(-1) for clockwise rotation

    bullet->setRotation(angle);
    game->scene->addItem(bullet);

}

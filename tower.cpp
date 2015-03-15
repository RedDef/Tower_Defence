#include "tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QLineF>
#include <QPolygonF>

Tower::Tower(QGraphicsItem *parent){
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

}

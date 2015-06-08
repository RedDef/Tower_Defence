 /***********************************************************************************/
/* tower is the basic tower class. redtower, blacktower... inherit from this class */
/***********************************************************************************/

#ifndef TOWER
#define TOWER

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QList>
#include "gridpoint.h"

class Tower: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event); //enter building-mode; changes mouse-cursor to tower-icon
    Tower(QGraphicsItem *parent=0);//constructor
    virtual void fire(); //function to fire bullets
    int shoot_speed=5;  //delay between he fires again ( 1 = fastest possible)
    void find_targetpoints(); //checks which enemy_points are in range of the tower
    int SCALE_FACTOR=100;  //range of the tower
    int damage; //bullet damage
    void setrange();
    int tower_cost; //cost of each tower to build
    QGraphicsPolygonItem *attack_area; //visualizes the range
    Gridpoint * TowersGridpoint;

public slots:
    void aquire_target(); //checks if a enemy is in his range

protected:

    QPointF attack_dest; //position of the enemy which gets attacked
    bool has_target = false;
    int steps_to_target; //checks position enemy to calculate flightpath of bullet
    int shoot_wait=0; //counter for shoot_speed

    /*range of tower --> rang[a][b] --> a = range number; b = beginning and end of range;
    if tower has multiple points in range, it creats different arrays to locate the possible points to aquire --> first dimension a,
    the beginning and ending point are stored in the second dimension b*/
    int range[10][2];

    int range_number=-1; //total of ranges for this tower
    int HittableEnemys[500];

};

#endif // TOWER


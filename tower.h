#ifndef TOWER
#define TOWER

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QList> //list<<element

/*
 * tower is the basic tower class. redtower, blacktower... inherit from this class

 * */


class Tower: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(QGraphicsItem *parent=0);
    virtual void fire(); //fires bullet
    int shoot_speed=5;  //delay between he fires again ( 1 =fastest possible)
    void find_targetpoints(); //checks whisch enemy_points are in range of the tower
    int SCALE_FACTOR=100;  //range of the tower
    int damage;

public slots:
    void aquire_target(); //checks if a enemy is in his range
protected:
    QGraphicsPolygonItem *attack_area; //visualizes the range
    QPointF attack_dest; //position of the enemy which gets attacked
    bool has_target = false;
    int i; //stupid counter i have to replace
    int point_index;

    int shoot_wait=0;

    int range[8][2];
    int range_number=-1;

private:

};

#endif // TOWER


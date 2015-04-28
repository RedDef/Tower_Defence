#ifndef TOWER
#define TOWER

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QList> //list<<element


class Tower: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(QGraphicsItem *parent=0);
    double distanceTo(QGraphicsItem *item);
    virtual void fire();
    int shoot_speed=5;
public slots:
    void aquire_target();
protected:
    QGraphicsPolygonItem *attack_area;
    QPointF attack_dest;
    bool has_target = false;
 private:
    QList<QPointF> way_points;
    int point_index;

    int shoot_wait=0;
};

#endif // TOWER


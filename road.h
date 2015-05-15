#ifndef ROAD_H
#define ROAD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

/*
 * road is the class which shows the path from the enemies
 *

 * */

class Road: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Road(QGraphicsItem *parent=0);
public slots:
protected:
};



#endif // ROAD_H


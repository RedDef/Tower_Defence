/***********************************************************/
/* road is the class which shows the path from the enemies */
/***********************************************************/

#ifndef ROAD_H
#define ROAD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Road: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Road(QGraphicsItem *parent=0);//constructor

};



#endif // ROAD_H


/***********************************************************/
/* area is the class which shows the area around the path */
/***********************************************************/

#ifndef AREA
#define AREA

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Area: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Area(QGraphicsItem *parent=0);//constructor

};

#endif // AREA


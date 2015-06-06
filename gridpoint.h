/**********************************************************************************************************************/
/* gridpoints are all over the screen, expect in the menu. on every gridpoint you can place one tower or a road piece */
/**********************************************************************************************************************/

#ifndef GRIDPOINT
#define GRIDPOINT

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Gridpoint: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Gridpoint(QGraphicsItem *parent=0);//constructor
    bool occupied; //defines if the gridpoint is occupied or not

};

#endif // GRIDPOINT


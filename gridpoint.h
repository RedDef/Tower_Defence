#ifndef GRIDPOINT
#define GRIDPOINT

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

/*
 * gridpoints are all over the screen. on every gridpoint you can place one tower or a road piece

 * */


class Gridpoint: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Gridpoint(QGraphicsItem *parent=0);
    double distanceTo(QGraphicsItem *item);
    bool occupied; //defines if the gridpoint occupied or not
public slots:
protected:
};

#endif // GRIDPOINT


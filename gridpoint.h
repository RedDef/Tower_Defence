#ifndef GRIDPOINT
#define GRIDPOINT

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Gridpoint: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Gridpoint(QGraphicsItem *parent=0);
    double distanceTo(QGraphicsItem *item);

public slots:
protected:
};

#endif // GRIDPOINT


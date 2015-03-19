#ifndef ENEMY
#define ENEMY

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> //list<<element
#include <QPointF>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
public slots:
    void move_foreward();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
};

#endif // ENEMY


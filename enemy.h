#ifndef ENEMY
#define ENEMY

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> //list<<element
#include <QPointF>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QList<QPointF> pointsToFollow, QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
    int STEP_SIZE;
    int step_count;
    double dx;
    double dy;
    int point_index;

public slots:
    void move_foreward();
private:
    QList<QPointF> points;
    QPointF dest;
    QPointF position;

    double theta;
};

#endif // ENEMY


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
    int STEP_SIZE;
    int step_count;
    double health_enemy;
    void hit(double damage);

public slots:
    void move_foreward();
private:
    QPointF position;
    int enemy_nr;
};

#endif // ENEMY


#ifndef ENEMY
#define ENEMY

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Enemy(QGraphicsItem * parent=0);//constructor
    int STEP_SIZE;//defines the speed of the enemy; how many points per step to skip in array way_points[]
    int step_count;//postion of the enemy in array way_points[]
    double health_enemy;

    /*function to reduce health of enemy; bullet calls this function by hitting the enemy;
      passes damage of the hitting bullet*/
    void hit(double damage);
    int enemy_worth; //worth of each enemy -> how much money if killed

public slots:
    void move_foreward();//moves enemy in array way_points[] foreward

protected:
    int enemy_nr;//enemy number in array enemy_list[] which includes all existing enemys

};

#endif // ENEMY


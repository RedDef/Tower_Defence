#ifndef BULLET
#define BULLET

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent=0);
    double damage_bullet; //defines how much damage the bullet has
    double dy; //dy and dx define the direction of the bullet.
    double dx;
    int STEP_SIZE;  //defines the speed of the bullet
    int steps_to_target; //if the bullet traveld further than the tower aimed bullet gets deleted


public slots:
    void move();    // moves the bullet

private:

    double distanceTravalled;   //counts how many steps the bullet made


};

#endif // BULLET



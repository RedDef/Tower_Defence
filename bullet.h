#ifndef BULLET
#define BULLET

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Bullet(QGraphicsItem *parent=0);//constructor
    double damage_bullet; //defines how much damage the bullet makes

    //dy and dx define the flight-direction of the bullet
    double dy;
    double dx;

    int STEP_SIZE;  //defines the speed of the bullet; how many pixel per step

    /*max. distance for bullet to travel bevore selfdistruction,
      callculated and set by the tower->aquire_target*/
    int steps_to_target;


public slots:
    void move(); //function to move the bullet

private:
    double distanceTravalled; //counts how many steps the bullet made

};

#endif // BULLET



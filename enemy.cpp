#include "enemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "game.h"

extern Game * game;

Enemy::Enemy(QList<QPointF> pointsToFollow, QGraphicsItem *parent){
    //set graphics
    setPixmap(QPixmap(":/images/enemy0.png"));

    step_count=0;
    STEP_SIZE=3;

    //set points
    points = pointsToFollow;
    point_index = 0;
    dest = points[0];

    //connect timer to move_foreward

    connect(game->move_timer,SIGNAL(timeout()),this,SLOT(move_foreward()));


    //setTransformOriginPoint(QPointF(18, 18));

}

void Enemy::rotateToPoint(QPointF p){
    QLineF ln(pos(), p);
    setRotation((ln.angle()));//(-1) turn clockwhise
}

void Enemy::move_foreward(){

    //increment the step_counter
      step_count++;

      position.setX(x()+18);
      position.setY(y()+18);

    //if close to dest, rotate to next dest
    QLineF ln(position, dest);
    if(ln.length() < STEP_SIZE){
        setPos(dest.x()-18, dest.y()-18);
        point_index++;
        if (point_index >= points.size()){//check if point_index is at the end (euqal to point.size
            return;
        }
        dest = points[point_index];
        dx = STEP_SIZE * game->direction[point_index-1][0];
        dy = STEP_SIZE * game->direction[point_index-1][1];

    }

    //move enemy foreward at current angle






    setPos(x()+dx, y()+dy);


}

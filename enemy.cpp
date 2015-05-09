#include "enemy.h"
#include "game.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>


extern Game * game;

Enemy::Enemy(QList<QPointF> pointsToFollow, QGraphicsItem *parent){
    //set graphics
    setPixmap(QPixmap(":/images/enemy0.png"));

    step_count=0;
    STEP_SIZE=3;
    health_enemy=10;

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

double Enemy::hit(double damage){
    health_enemy = health_enemy - damage;

    if (health_enemy <= 0) {

        scene()->removeItem(this);

        // increase Score
        game->score->increase();

        // delete them from the heap to save memory
        delete this;
    }
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

    //decrease health when reaches finish
    if(pos().x() > 779){
        game->health->decrease();
    }

    // Endposition noch anpassen, damit es nur einmal zählt
    // momentan io, aber nur solange der x-Wert des Endpunktes nicht verändert wird (594)
    // und die Enemys wieder zurücklaufen, also übers Spielfeld hinaus


}

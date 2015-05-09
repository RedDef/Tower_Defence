#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    //initialize health
    health = 20;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 20
    setDefaultTextColor(Qt::blue);
    setPos(x()+730,y()+450);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth(){
    return health;
}


#include "road.h"


Road::Road(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //set the graphics
    setPixmap(QPixmap(":/images/background_road.png"));

}

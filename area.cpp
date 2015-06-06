#include "area.h"

Area::Area(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //set the graphics
    setPixmap(QPixmap(":/images/background_field_green.png"));

}

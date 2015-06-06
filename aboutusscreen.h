#ifndef SCREEN_ABOUTUS
#define SCREEN_ABOUTUS

#include <QGraphicsPixmapItem>

class AboutusScreen: public QGraphicsPixmapItem{

public:
    AboutusScreen(QGraphicsItem *parent=0);//constructor
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // SCREEN_ABOUTUS


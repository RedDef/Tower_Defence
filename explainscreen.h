#ifndef EXPLAINSCREEN
#define EXPLAINSCREEN

#include <QGraphicsPixmapItem>

class ExplainScreen: public QGraphicsPixmapItem{

public:
    ExplainScreen(QGraphicsItem *parent=0);//constructor
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // EXPLAINSCREEN


#ifndef BUILDBLUETOWERICON
#define BUILDBLUETOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildBlueTowerIcon: public QGraphicsPixmapItem{
public:
    BuildBlueTowerIcon(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDBLUETOWERICON


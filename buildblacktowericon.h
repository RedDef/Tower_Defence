#ifndef BUILDBLACKTOWERICON
#define BUILDBLACKTOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildBlackTowerIcon: public QGraphicsPixmapItem{
public:
    BuildBlackTowerIcon(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDBLACKTOWERICON


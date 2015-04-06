#ifndef BUILDGREENTOWERICON
#define BUILDGREENTOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildGreenTowerIcon: public QGraphicsPixmapItem{
public:
    BuildGreenTowerIcon(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDGREENTOWERICON


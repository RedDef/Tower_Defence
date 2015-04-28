#ifndef BUILDYELLOWTOWERICON
#define BUILDYELLOWTOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildYellowTowerIcon: public QGraphicsPixmapItem{
public:
    BuildYellowTowerIcon(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDYELLOWTOWERICON


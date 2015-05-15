#ifndef BUILDYELLOWTOWERICON
#define BUILDYELLOWTOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

/*
 * buildyellowtower ist the icon in the player menu
 * if you click on it you can build a yellow tower

 * */

class BuildYellowTowerIcon: public QGraphicsPixmapItem{
public:
    BuildYellowTowerIcon(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDYELLOWTOWERICON


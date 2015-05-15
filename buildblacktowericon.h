#ifndef BUILDBLACKTOWERICON
#define BUILDBLACKTOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

/*
 * buildblacktower ist the icon in the player menu
 * if you click on it you can build a balck tower

 * */

class BuildBlackTowerIcon: public QGraphicsPixmapItem{
public:
    BuildBlackTowerIcon(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDBLACKTOWERICON


#ifndef BUILDREDTOWERICON
#define BUILDREDTOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

/*
 * buildgredtower ist the icon in the player menu
 * if you click on it you can build a red tower

 * */

class BuildRedTowerIcon: public QGraphicsPixmapItem{
public:
    BuildRedTowerIcon(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDREDTOWERICON


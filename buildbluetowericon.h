#ifndef BUILDBLUETOWERICON
#define BUILDBLUETOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

/*
 * buildbluetower ist the icon in the player menu
 * if you click on it you can build a blue tower

 * */

class BuildBlueTowerIcon: public QGraphicsPixmapItem{
public:
    BuildBlueTowerIcon(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDBLUETOWERICON


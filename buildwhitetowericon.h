#ifndef BUILDWHITETOWERICON
#define BUILDWHITETOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

/*
 * buildwhitetower ist the icon in the player menu
 * if you click on it you can build a white tower

 * */

class BuildWhiteTowerIcon: public QGraphicsPixmapItem{
public:
    BuildWhiteTowerIcon(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDWHITETOWERICON


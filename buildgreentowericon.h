#ifndef BUILDGREENTOWERICON
#define BUILDGREENTOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

/*
 * buildgreentower ist the icon in the player menu
 * if you click on it you can build a green tower

 * */
class BuildGreenTowerIcon: public QGraphicsPixmapItem{
public:
    BuildGreenTowerIcon(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDGREENTOWERICON


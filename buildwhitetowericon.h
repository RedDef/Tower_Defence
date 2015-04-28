#ifndef BUILDWHITETOWERICON
#define BUILDWHITETOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildWhiteTowerIcon: public QGraphicsPixmapItem{
public:
    BuildWhiteTowerIcon(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDWHITETOWERICON


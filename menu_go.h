#ifndef MENU_GO
#define MENU_GO

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Menu_Go: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Menu_Go(QGraphicsItem *parent=0);//constructor
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // MENU_GO


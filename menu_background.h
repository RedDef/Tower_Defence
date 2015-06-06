#ifndef MENU_BACKGROUND
#define MENU_BACKGROUND

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Menu_Background: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Menu_Background(QGraphicsItem *parent=0);//constructor

};

#endif // MENU_BACKGROUND


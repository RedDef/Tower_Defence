#ifndef MENU_EXPLAIN
#define MENU_EXPLAIN

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsView>
#include "game.h"
#include "explainscreen.h"

class Menu_Explain: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Menu_Explain(QGraphicsItem *parent=0);//constructor
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ExplainScreen *explain;

};

#endif // MENU_EXPLAIN


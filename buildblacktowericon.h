/*************************************************************************************************/
/* buildblacktower ist the icon in the play menu. if you click on it you can build a black tower */
/*************************************************************************************************/

#ifndef BUILDBLACKTOWERICON
#define BUILDBLACKTOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildBlackTowerIcon: public QGraphicsPixmapItem{

public:
    BuildBlackTowerIcon(QGraphicsItem *parent=0);//constructor
    void mousePressEvent(QGraphicsSceneMouseEvent *event); //enter building-mode; changes mouse-cursor to tower-icon
    void setIcon(bool status);
    void showText();
    void hideText();
    void buildTower();

private:
    bool old_icon=true;

};

#endif // BUILDBLACKTOWERICON


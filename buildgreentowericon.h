/*************************************************************************************************/
/* buildgreentower ist the icon in the play menu. if you click on it you can build a green tower */
/*************************************************************************************************/

#ifndef BUILDGREENTOWERICON
#define BUILDGREENTOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildGreenTowerIcon: public QGraphicsPixmapItem{

public:
    BuildGreenTowerIcon(QGraphicsItem *parent=0);//constructor
    void mousePressEvent(QGraphicsSceneMouseEvent *event);//enter building-mode; changes mouse-cursor to tower-icon
    void setIcon(bool status);
    void showText();
    void hideText();

private:
    bool old_icon=true;

};

#endif // BUILDGREENTOWERICON


/*********************************************************************************************/
/* buildredtower ist the icon in the play menu. if you click on it you can build a red tower */
/*********************************************************************************************/

#ifndef BUILDREDTOWERICON
#define BUILDREDTOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildRedTowerIcon: public QGraphicsPixmapItem{

public:
    BuildRedTowerIcon(QGraphicsItem *parent=0);//constructor
    void mousePressEvent(QGraphicsSceneMouseEvent *event);//enter building-mode; changes mouse-cursor to tower-icon
    void setIcon(bool status);
    void showText();
    void hideText();

private:
    bool old_icon=true;

};

#endif // BUILDREDTOWERICON


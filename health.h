#ifndef HEALTH
#define HEALTH

#include <QGraphicsTextItem>

/*
 * shows how many lives the player has left befor the game is over

 * */

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=0);
    void decrease(); //decreases the health
    int getHealth(); //gives back the health
private:
    int health;
};

#endif // HEALTH


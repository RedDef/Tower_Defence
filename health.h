/*******************************************************************/
/* shows how many lives the player has left befor the game is over */
/*******************************************************************/

#ifndef HEALTH
#define HEALTH

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{

public:
    Health(QGraphicsItem * parent=0);//constructor
    void decrease(); //decreases the health
    int getHealth(); //gives back the health
    void setHealth(int newHealth);

private:
    int health;

};

#endif // HEALTH


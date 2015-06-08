/*********************************************************/
/* shows on the sceen how much money you have            */
/*********************************************************/

#ifndef MONEY
#define MONEY


#include <QGraphicsTextItem>

class Money: public QGraphicsTextItem{

public:
    Money (QGraphicsItem * parent=0);   //constructor
    void increase(int enemy_worth);    //function increases the money
    void decrease(int tower_cost);
    int getMoney();
    void setMoney(int newMoney);

    void setBuildIcons();

private:
    int money;

};


#endif // MONEY


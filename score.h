/*********************************************************/
/* shows on the sceen how many enemys you have destroyed */
/*********************************************************/


#ifndef SCORE
#define SCORE


#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{

public:
    Score(QGraphicsItem * parent=0);//constructor
    void increase();//function increases the score
    int getScore();

private:
    int score;
};

#endif // SCORE


#ifndef SCORE
#define SCORE


#include <QGraphicsTextItem>

/*
 * shows on the sceen how many enemys you have destroyed

 * */

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void increase();
    int getScore();
private:
    int score;
};

#endif // SCORE


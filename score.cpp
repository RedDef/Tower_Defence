#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){

     //initialize score
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::lightGray);
    setFont(QFont("times",16));
}

void Score::increase(){
    score = score+1;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}

void Score::setScore(int newScore)
{
    score=newScore;
    setPlainText(QString("Score: ") + QString::number(score));
}

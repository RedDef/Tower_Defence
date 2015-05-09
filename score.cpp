#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
     //initialize score
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::gray);
    setPos(x()+730,y()+500);
    setFont(QFont("times",16));
}

void Score::increase(){
    score = score+1;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}

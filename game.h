#ifndef GAME
#define GAME

#include <QGraphicsView>
#include <QMouseEvent>

class Game: public QGraphicsView{
public:
    //member functions
    Game();
    void mousePressEvent(QMouseEvent *event);

    //member attributes
    QGraphicsScene *scene;

};

#endif // GAME


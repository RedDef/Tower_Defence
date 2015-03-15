#ifndef GAME
#define GAME

#include <QGraphicsView>

class Game: public QGraphicsView{
public:
    //member functions
    Game();

    //member attributes
    QGraphicsScene *scene;

};

#endif // GAME


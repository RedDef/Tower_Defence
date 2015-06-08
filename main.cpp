#include "game.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>


Game *game;


void restart(){
    delete game;
    game = new Game();
    game->show();
}


int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    //create a scene

    game = new Game();
    game->show();

    return a.exec();
}

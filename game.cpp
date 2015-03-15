#include "game.h"
#include "tower.h"
#include <QGraphicsScene>

Game::Game(){
    //create a scene
    scene = new QGraphicsScene(this);

    //set the scene
    setScene(scene);

    //create a tower
    Tower *t = new Tower();

    //add the tower to scene
    scene->addItem(t);

    setFixedSize(1200,800);
}

#include "game.h"
#include "redtower.h"
#include "bullet.h"
#include "enemy.h"
#include "buildredtowericon.h"
#include "buildbluetowericon.h"
#include "buildgreentowericon.h"
#include <QGraphicsScene>

Game::Game(): QGraphicsView(){
    //create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1200,800);

    //set the scene
    setScene(scene);

    //create a tower
    //Tower *t = new Tower();
    //t->setPos(250,250);

    //add the tower to scene
    //scene->addItem(t);

    //set cursor
    cursor = nullptr;
    build = nullptr;
    setMouseTracking(true);

    //alter window
    setFixedSize(1200,800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //creat enemy
    Enemy * enemy = new Enemy();
    scene->addItem(enemy);

    //create Tower-Icon
    BuildRedTowerIcon * rt = new BuildRedTowerIcon();
    BuildGreenTowerIcon * gt = new BuildGreenTowerIcon();
    BuildBlueTowerIcon * bt = new BuildBlueTowerIcon();

    //move tower icons
    gt->setPos(x(),y()+50);
    bt->setPos(x(),y()+100);

    scene->addItem(rt);
    scene->addItem(gt);
    scene->addItem(bt);

}

void Game::setCursor(QString filename){
    if(cursor){
        scene->removeItem(cursor);
        delete cursor;
    }

    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event){
    if(cursor){
        cursor->setPos(event->pos());
    }

}

void Game::mousePressEvent(QMouseEvent *event){
    if(build){
        //return if cursor is coliding with a tower
        QList<QGraphicsItem *> items = cursor->collidingItems();
        for(size_t i=0, n = items.size(); i<n; i++){
            if(dynamic_cast<Tower *>(items[i])){
                return;
            }
        }

        //otherwise build at the clicked location
        scene->addItem(build);
        build->setPos(event->pos());
        cursor = nullptr;
        build = nullptr;
    }
    else{
        QGraphicsView::mousePressEvent(event);
    }
}



#include "game.h"
#include "bullet.h"
#include "enemy.h"
#include "score.h"
#include "health.h"
#include "gridpoint.h"
#include "buildredtowericon.h"
#include "buildbluetowericon.h"
#include "buildgreentowericon.h"
#include "buildblacktowericon.h"
#include "buildwhitetowericon.h"
#include "buildyellowtowericon.h"
#include <QDebug>
#include <QTimer>
#include <QPen>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <qmath.h>


Game::Game(): QGraphicsView(){
move_timer = new QTimer(this);

    move_timer->start(20);

    //create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,920,720);

    //set the scene
    setScene(scene);

    //set cursor
    cursor = nullptr;
    building = nullptr;
    setMouseTracking(true);

    //alter window
    setFixedSize(920,720);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //split screen into playfield and menu
    field_menu << QPointF(720,0) << QPointF(720,720);
    for(size_t i=0, n = field_menu.size()-1; i < n; i++){
        //create a line
        QLineF line(field_menu[i],field_menu[i+1]);
        QGraphicsLineItem * lineItem = new QGraphicsLineItem(line);

        QPen pen;
        pen.setWidth(5);
        pen.setColor(Qt::black);

        lineItem->setPen(pen);

        scene->addItem(lineItem);
    }

    //create gridpoints
    for(gPoint_x=0; gPoint_x<20; gPoint_x++){
        for(gPoint_y=0; gPoint_y<20; gPoint_y++){
            Gridpoint *gPoint = new Gridpoint;
            gPoint->setPos(x()+12+(36*gPoint_x),y()+12+(36*gPoint_y));
            scene->addItem(gPoint);
        }
    }

    //creat enemy
    spawnTimer = new QTimer(this);
    enemiesSpawned = 0;
    maxNumberOfEnemies = 0;
    pointsToFollow  << QPointF(18,18) << QPointF(18,414) << QPointF(198,414)<<  QPointF(594,414) << QPointF(594,54) << QPointF(800,54)<< QPointF(594,54);



    for(int i=0;i<=(pointsToFollow.length()-2);i++){
        QPointF temp;
        double test;
        temp=((pointsToFollow[i+1])-(pointsToFollow[i]));
        temp=temp;
        direction[i][0]=temp.x()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));
        direction[i][1]=temp.y()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));

    }


    createEnemies(20);

    //create Road
    createRoad();

    //create Tower-Icon
    BuildRedTowerIcon * rt = new BuildRedTowerIcon();
    BuildGreenTowerIcon * gt = new BuildGreenTowerIcon();
    BuildBlueTowerIcon * bt = new BuildBlueTowerIcon();
    BuildBlackTowerIcon * bkt = new BuildBlackTowerIcon();
    BuildWhiteTowerIcon * wt = new BuildWhiteTowerIcon();
    BuildYellowTowerIcon * yt = new BuildYellowTowerIcon();

    //move tower icons
    rt->setPos(x()+850,y());
    gt->setPos(x()+850,y()+50);
    bt->setPos(x()+850,y()+100);
    bkt->setPos(x()+850,y()+150);
    yt->setPos(x()+850,y()+200);
    wt->setPos(x()+850,y()+250);

    scene->addItem(rt);
    scene->addItem(gt);
    scene->addItem(bt);
    scene->addItem(bkt);
    scene->addItem(yt);
    scene->addItem(wt);

    // create Score Text
    score = new Score();
    scene->addItem(score);

    // create Health Text
    health = new Health();
    scene->addItem(health);

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
        cursor->setPos((event->pos().x()-18),(event->pos().y())-18);
    }

}

void Game::mousePressEvent(QMouseEvent *event){
    if(building){
        qDebug() << "if build ";
        //return if cursor is coliding with a tower
        QList<QGraphicsItem *> items = cursor->collidingItems();

        double closest_dist = 5000;
        bool has_gridpoint=false;

        int closest_gridpoint = 100;


        for(size_t i=0, n = items.size(); i<n; i++){
            Gridpoint *temp_gridpoint = dynamic_cast<Gridpoint *>(items[i]);
            if(temp_gridpoint){
                has_gridpoint=true;

                QLineF ln(pos(),items[i]->pos());

                if(ln.length() < closest_dist){
                    closest_dist = ln.length();
                    closest_gridpoint = i;

                }
            }
        }
        if(has_gridpoint){
            Gridpoint *temp_gridpoint = dynamic_cast<Gridpoint *>(items[closest_gridpoint]);
            if(temp_gridpoint->occupied==0){

                temp_gridpoint->occupied=1;
                scene->addItem(building);
                building->setPos((temp_gridpoint->pos().x()-12),(temp_gridpoint->pos().y()-12));
                cursor->setPos((temp_gridpoint->pos().x()-12),(temp_gridpoint->pos().y()-12));
                cursor = nullptr;
                building = nullptr;
            }
        }
        has_gridpoint=false;
        return;
    }


    else{
        QGraphicsView::mousePressEvent(event);
    }
}

void Game::createEnemies(int numberOfEnemies){
    enemiesSpawned = 0;
    maxNumberOfEnemies = numberOfEnemies;
    connect(spawnTimer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    spawnTimer->start(1173);

}

void Game::createRoad(){
    /*for(size_t i=0, n = pointsToFollow.size()-1; i < n; i++){
        //create a line
        QLineF line(pointsToFollow[i],pointsToFollow[i+1]);
        QGraphicsLineItem * lineItem = new QGraphicsLineItem(line);

        QPen pen;
        pen.setWidth(50);
        pen.setColor(Qt::darkGray);

        lineItem->setPen(pen);

        scene->addItem(lineItem);
    }*/
}

void Game::spawnEnemy(){
    //spawn an enemy
    Enemy * enemy = new Enemy(pointsToFollow);
    enemy->setPos((pointsToFollow[0].x()-18),(pointsToFollow[0].y()-18));
    scene->addItem(enemy);
    enemiesSpawned += 1;

    if(enemiesSpawned >= maxNumberOfEnemies){
        spawnTimer->disconnect();
    }
}



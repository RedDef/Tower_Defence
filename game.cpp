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
#include "enemy_point.h"




Game::Game(): QGraphicsView(){

    move_timer->start(40);

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
    enemiesSpawned = 0;
    maxNumberOfEnemies = 0;
    createEnemies(100000);


    // define way. wher the enemys change the direction
    pointsToFollow  << QPointF(18,18) << QPointF(18,702) << QPointF(90,702)<<  QPointF(90,18)<< QPointF(162,18)<< QPointF(162,702)<<QPointF(234,702)<< QPointF(234,18)
                    << QPointF(306,18)<< QPointF(306,702)<< QPointF(378,702)<< QPointF(378,18)
                    << QPointF(450,18)<< QPointF(450,702)<< QPointF(522,702)<< QPointF(522,18)
                    << QPointF(594,18)<< QPointF(594,702)<< QPointF(702,702)<<QPointF(702,18);


    //this is an array where you can look up in which direction you have to go to get to the next point (pointsToTollow)
    for(int i=0;i<=(pointsToFollow.length()-2);i++){
        QPointF temp;
        temp=((pointsToFollow[i+1])-(pointsToFollow[i]));
        direction[i][0]=temp.x()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));
        direction[i][1]=temp.y()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));

    }


    //clears the enemy list
    for(int i=0;i<500;i++){
        enemy_list[i]=(-1);
    }

    //sets the position of the array enemy_waypoint and counts how many waypoints this game has
    last_waypoint=set_waypoints();




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

    //create Road
    createRoad();

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
                building->find_targetpoints();
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
    connect(move_timer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
}

void Game::createRoad(){

    Road * build_way = new Road();
    scene->addItem(build_way);
    build_way->setPos(way_points[0].position_enemy);
    build_way->setPos(build_way->x()-18,build_way->y()-18);
    bool has_gridpoint=false;

        for(int count=0;count<=last_waypoint;count++){


            build_way->setPos(way_points[count].position_enemy);
            QList<QGraphicsItem *> items = build_way->collidingItems();
            int max = items.size();
            double closest_dist = 5000;


            int closest_gridpoint = 100;


            for(int fuck=0; fuck<max; fuck++){
                Gridpoint *temp_gridpoint = dynamic_cast<Gridpoint *>(items[fuck]);
                if(temp_gridpoint){
                    has_gridpoint=true;

                    QLineF ln(pos(),items[fuck]->pos());

                    if(ln.length() < closest_dist){
                        closest_dist = ln.length();
                        closest_gridpoint = fuck;

                    }
                }
            }
            if(has_gridpoint){
                Gridpoint *temp_gridpoint = dynamic_cast<Gridpoint *>(items[closest_gridpoint]);
                if(temp_gridpoint->occupied==0){

                    temp_gridpoint->occupied=1;
                    scene->addItem(build_way);
                    build_way->setPos((temp_gridpoint->pos().x()-12),(temp_gridpoint->pos().y()-12));
                    build_way = new Road();
                    scene->addItem(build_way);
                }
            }
            has_gridpoint=false;
        }
}

int Game::set_waypoints()
{
    int point_index=0;
    int step_counter=0;
    double dx=0;
    double dy=0;
    QPointF dest=pointsToFollow[0];
    QPointF position=pointsToFollow[0];




      while(true){
          //increment the step_counter
            step_counter++;

          //if close to dest, rotate to next dest
          QLineF ln(position, dest);
          if(ln.length() <= 1){
              point_index++;
              qDebug() << "test enemy " << direction;


              if (point_index >= pointsToFollow.size()){//check if point_index is at the end (euqal to point.size
                 return(step_counter);
              }
              dest = pointsToFollow[point_index];
              dx = direction[point_index-1][0];
              dy = direction[point_index-1][1];

          }

          //move enemy foreward at current angle
          position.setX(position.x()+dx);
          position.setY(position.y()+dy);

          way_points[step_counter].position_enemy=position;

      }
}


void Game::spawnEnemy(){
    //spawn an enemy
    if(delay_spawn_enemys==0){


        Enemy * enemy = new Enemy();
        enemy->setPos((pointsToFollow[0].x()-18),(pointsToFollow[0].y()-18));
        scene->addItem(enemy);
        enemiesSpawned += 1;
    }
    delay_spawn_enemys++;
    if(delay_spawn_enemys==20){
        delay_spawn_enemys=0;
    }


    if(enemiesSpawned >= maxNumberOfEnemies){
         disconnect(move_timer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    }
}



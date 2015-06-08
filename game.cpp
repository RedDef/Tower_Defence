#include "game.h"
#include "bullet.h"
#include "enemy.h"
#include "score.h"
#include "health.h"
#include "gridpoint.h"
#include <QDebug>
#include <QTimer>
#include <QPen>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <qmath.h>
#include "enemy_list_element.h"
#include "yellowenemy.h"
#include "greenenemy.h"
#include "blueenemy.h"
#include "orangeenemy.h"
#include "violetenemy.h"
#include "redenemy.h"
#include "bluetower.h"
#include "blacktower.h"
#include "whitetower.h"
#include "yellowtower.h"
#include "greentower.h"
#include "redtower.h"
#include "area.h"
#include "menu_background.h"
#include "menu_about.h"
#include "menu_explain.h"
#include "menu_go.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QTextEdit>

extern QGraphicsScene *scenemain;

Game::Game(): QGraphicsView(){
    focusedTower=nullptr;

    //set cursor
    cursor = nullptr;
    building = nullptr;
    setMouseTracking(true);

    global_timer->start(40);

    //create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,920,720);

    //set the scene
    setScene(scene);


    //alter window
    setFixedSize(922,722);
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
    for(int gPoint_x=0; gPoint_x<20; gPoint_x++){

        for(int gPoint_y=0; gPoint_y<20; gPoint_y++){
            Gridpoint *gPoint = new Gridpoint;
            gPoint->setPos(x()+12+(36*gPoint_x),y()+12+(36*gPoint_y));//12-> gridpoint = 12px; field = 18px; field - (gridpoint/2) = 12px
            scene->addItem(gPoint);
        }
    }

    //create area
    for(int gPoint_x=0; gPoint_x<20; gPoint_x++){

        for(int gPoint_y=0; gPoint_y<20; gPoint_y++){
            Area *area = new Area;
            area->setPos(x()+(36*gPoint_x),y()+(36*gPoint_y));//12-> gridpoint = 12px; field = 18px; field - (gridpoint/2) = 12px
            scene->addItem(area);
        }
    }

    //connect spawn enemies
    enemiesSpawned = 0;
    connect(global_timer,SIGNAL(timeout()),this,SLOT(creatEnemies()));

    //connect timer with tower
    connect(global_timer,SIGNAL(timeout()),this,SLOT(createtowers()));


    // define way. wher the enemys change the direction
    pointsToFollow  << QPointF(54,18)<<QPointF(54,162)<<  QPointF(162,162)<<  QPointF(162,54)<< QPointF(234,54)<< QPointF(234,234)<<QPointF(54,234)<< QPointF(54,666)
                    << QPointF(378,666)<< QPointF(378,378)<< QPointF(270,378)<< QPointF(270,558)
                    << QPointF(162,558)<< QPointF(162,306)<< QPointF(594,306)<< QPointF(594,486)
                    << QPointF(486,486)<< QPointF(486,558)<< QPointF(594,558)<<QPointF(594,666)
                    << QPointF(702,666)<< QPointF(702,126)<< QPointF(486,126)<<QPointF(486,54);


    //this is an array where you can look up in which direction you have to go to get to the next point (pointsToFollow)
    for(int i=0;i<=(pointsToFollow.length()-2);i++){
        QPointF temp;
        temp=((pointsToFollow[i+1])-(pointsToFollow[i]));
        direction[i][0]=temp.x()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));
        direction[i][1]=temp.y()/(sqrt(pow(temp.x(),2)+pow(temp.y(),2)));

    }


    //sets the position of the array enemy_waypoint and counts how many waypoints this game has
    last_waypoint=set_waypoints();

    //Background Menu
    Menu_Background *mback = new Menu_Background;
    mback->setPos(722,0);
    scene->addItem(mback);
    Menu_Background *mback1 = new Menu_Background;
    mback1->setPos(722,2);
    scene->addItem(mback1);


    //create the menu buttons ?, About, Go
    Menu_About *aboutus = new Menu_About;
    Menu_Explain *mexp = new Menu_Explain;

    startbutton = new Menu_Go;

    aboutus->setPos(730,550);
    mexp->setPos(850,570);
    startbutton->setPos(775,650);

    scene->addItem(aboutus);
    scene->addItem(mexp);
    scene->addItem(startbutton);

    //create Tower-Icon in the menu
    rt = new BuildRedTowerIcon();
    gt = new BuildGreenTowerIcon();
    bt = new BuildBlueTowerIcon();
    bkt = new BuildBlackTowerIcon();
    wt = new BuildWhiteTowerIcon();
    yt = new BuildYellowTowerIcon();

    //move tower icons
    rt->setPos(x()+750,y()+5);
    gt->setPos(x()+750,y()+90);
    bt->setPos(x()+750,y()+175);
    yt->setPos(x()+850,y()+5);
    wt->setPos(x()+850,y()+90);
    bkt->setPos(x()+850,y()+175);

    scene->addItem(rt);
    scene->addItem(gt);
    scene->addItem(bt);
    scene->addItem(bkt);
    scene->addItem(yt);
    scene->addItem(wt);

    //**********************
    costRedTower=50;
    costGreenTower= 100;
    costBlueTower= 300;
    costYellowTower= 800;
    costWhiteTower= 1500;
    costBlackTower= 3500;


    // create Score Text
    score = new Score();
    score->setPos(x()+730,y()+470);
    scene->addItem(score);

    // create Health Text
    health = new Health();
    health->setPos(x()+730,y()+420);
    scene->addItem(health);

    // create money Text
    money = new Money();
    money->setPos(x()+730,y()+370);
    scene->addItem(money);

    //create Road
    createRoad();

}

void Game::createtowers(){

    //whitening of the icons
    money->setBuildIcons();

    /**************************************/
    /*          RED Tower                 */
    /**************************************/

    //create Tower
    RedTower *red = new RedTower();
    scene->addItem(red);
    red->setPos(0,0);

    costRedTower=red->tower_cost;


    //text cost under icon
    redcost_1 = new QGraphicsTextItem;
    redcost_1->setPlainText(QString("Cost: ") + QString::number(red->tower_cost));
    redcost_1->setDefaultTextColor(Qt::black);
    redcost_1->setFont(QFont("times",10));
    redcost_1->setPos(740,54);
    scene->addItem(redcost_1);

    //text damage
    reddamage = new QGraphicsTextItem;
    reddamage->setPlainText(QString("Damage: ") + QString::number(red->damage));
    reddamage->setDefaultTextColor(Qt::black);
    reddamage->setFont(QFont("times",12));
    reddamage->setPos(750,260);
    scene->addItem(reddamage);
    reddamage->hide();

    //text range
    redrange = new QGraphicsTextItem;
    redrange->setPlainText(QString("Range: ") + QString::number(red->SCALE_FACTOR));
    redrange->setDefaultTextColor(Qt::black);
    redrange->setFont(QFont("times",12));
    redrange->setPos(750,292);
    scene->addItem(redrange);
    redrange->hide();

    //text speed
    redspeed = new QGraphicsTextItem;
    redspeed->setPlainText(QString("Shoot Delay: ") + QString::number(red->shoot_speed));
    redspeed->setDefaultTextColor(Qt::black);
    redspeed->setFont(QFont("times",12));
    redspeed->setPos(750,324);
    scene->addItem(redspeed);
    redspeed->hide();

    //delete added tower
    scene->removeItem(red);
    delete red;

    /**************************************/
    /*          GREEN Tower               */
    /**************************************/

    //create Tower
    GreenTower *green = new GreenTower();
    scene->addItem(green);
    green->setPos(0,0);

    costGreenTower= green->tower_cost;


    //text cost under icon
    greencost_1 = new QGraphicsTextItem;
    greencost_1->setPlainText(QString("Cost: ") + QString::number(green->tower_cost));
    greencost_1->setDefaultTextColor(Qt::black);
    greencost_1->setFont(QFont("times",10));
    greencost_1->setPos(740,140);
    scene->addItem(greencost_1);



    //text damage
    greendamage = new QGraphicsTextItem;
    greendamage->setPlainText(QString("Damage: ") + QString::number(green->damage));
    greendamage->setDefaultTextColor(Qt::black);
    greendamage->setFont(QFont("times",12));
    greendamage->setPos(750,260);
    scene->addItem(greendamage);
    greendamage->hide();

    //text range
    greenrange = new QGraphicsTextItem;
    greenrange->setPlainText(QString("Range: ") + QString::number(green->SCALE_FACTOR));
    greenrange->setDefaultTextColor(Qt::black);
    greenrange->setFont(QFont("times",12));
    greenrange->setPos(750,292);
    scene->addItem(greenrange);
    greenrange->hide();

    //text speed
    greenspeed = new QGraphicsTextItem;
    greenspeed->setPlainText(QString("Shoot Delay: ") + QString::number(green->shoot_speed));
    greenspeed->setDefaultTextColor(Qt::black);
    greenspeed->setFont(QFont("times",12));
    greenspeed->setPos(750,324);
    scene->addItem(greenspeed);
    greenspeed->hide();

    //delete added tower
    scene->removeItem(green);
    delete green;

    /**************************************/
    /*          BLUE Tower                */
    /**************************************/

    //create Tower
    BlueTower *blue = new BlueTower();
    scene->addItem(blue);
    blue->setPos(0,0);

    costBlueTower= blue->tower_cost;


    //text cost under icon
    bluecost_1 = new QGraphicsTextItem;
    bluecost_1->setPlainText(QString("Cost: ") + QString::number(blue->tower_cost));
    bluecost_1->setDefaultTextColor(Qt::black);
    bluecost_1->setFont(QFont("times",10));
    bluecost_1->setPos(740,226);
    scene->addItem(bluecost_1);

    //text damage
    bluedamage = new QGraphicsTextItem;
    bluedamage->setPlainText(QString("Damage: ") + QString::number(blue->damage));
    bluedamage->setDefaultTextColor(Qt::black);
    bluedamage->setFont(QFont("times",12));
    bluedamage->setPos(750,260);
    scene->addItem(bluedamage);
    bluedamage->hide();

    //text range
    bluerange = new QGraphicsTextItem;
    bluerange->setPlainText(QString("Range: ") + QString::number(blue->SCALE_FACTOR));
    bluerange->setDefaultTextColor(Qt::black);
    bluerange->setFont(QFont("times",12));
    bluerange->setPos(750,292);
    scene->addItem(bluerange);
    bluerange->hide();

    //text speed
    bluespeed = new QGraphicsTextItem;
    bluespeed->setPlainText(QString("Shoot Delay: ") + QString::number(blue->shoot_speed));
    bluespeed->setDefaultTextColor(Qt::black);
    bluespeed->setFont(QFont("times",12));
    bluespeed->setPos(750,324);
    scene->addItem(bluespeed);
    bluespeed->hide();

    //delete added tower
    scene->removeItem(blue);
    delete blue;

    /**************************************/
    /*          YELLOW Tower              */
    /**************************************/

    //create Tower
    YellowTower *yellow = new YellowTower();
    scene->addItem(yellow);
    yellow->setPos(0,0);

    costYellowTower= yellow->tower_cost;


    //text cost under icon
    yellowcost_1 = new QGraphicsTextItem;
    yellowcost_1->setPlainText(QString("Cost: ") + QString::number(yellow->tower_cost));
    yellowcost_1->setDefaultTextColor(Qt::black);
    yellowcost_1->setFont(QFont("times",10));
    yellowcost_1->setPos(835,54);
    scene->addItem(yellowcost_1);

    //text damage
    yellowdamage = new QGraphicsTextItem;
    yellowdamage->setPlainText(QString("Damage: ") + QString::number(yellow->damage));
    yellowdamage->setDefaultTextColor(Qt::black);
    yellowdamage->setFont(QFont("times",12));
    yellowdamage->setPos(750,260);
    scene->addItem(yellowdamage);
    yellowdamage->hide();

    //text range
    yellowrange = new QGraphicsTextItem;
    yellowrange->setPlainText(QString("Range: ") + QString::number(yellow->SCALE_FACTOR));
    yellowrange->setDefaultTextColor(Qt::black);
    yellowrange->setFont(QFont("times",12));
    yellowrange->setPos(750,292);
    scene->addItem(yellowrange);
    yellowrange->hide();

    //text speed
    yellowspeed = new QGraphicsTextItem;
    yellowspeed->setPlainText(QString("Shoot Delay: ") + QString::number(yellow->shoot_speed));
    yellowspeed->setDefaultTextColor(Qt::black);
    yellowspeed->setFont(QFont("times",12));
    yellowspeed->setPos(750,324);
    scene->addItem(yellowspeed);
    yellowspeed->hide();

    //delete added tower
    scene->removeItem(yellow);
    delete yellow;

    /**************************************/
    /*          WHITE Tower               */
    /**************************************/

    //create Tower
    WhiteTower *white = new WhiteTower();
    scene->addItem(white);
    white->setPos(0,0);

    costWhiteTower= white->tower_cost;



    //text cost under icon
    whitecost_1 = new QGraphicsTextItem;
    whitecost_1->setPlainText(QString("Cost: ") + QString::number(white->tower_cost));
    whitecost_1->setDefaultTextColor(Qt::black);
    whitecost_1->setFont(QFont("times",10));
    whitecost_1->setPos(835,140);
    scene->addItem(whitecost_1);

    //text damage
    whitedamage = new QGraphicsTextItem;
    whitedamage->setPlainText(QString("Damage: ") + QString::number(white->damage));
    whitedamage->setDefaultTextColor(Qt::black);
    whitedamage->setFont(QFont("times",12));
    whitedamage->setPos(750,260);
    scene->addItem(whitedamage);
    whitedamage->hide();

    //text range
    whiterange = new QGraphicsTextItem;
    whiterange->setPlainText(QString("Range: ") + QString::number(white->SCALE_FACTOR));
    whiterange->setDefaultTextColor(Qt::black);
    whiterange->setFont(QFont("times",12));
    whiterange->setPos(750,292);
    scene->addItem(whiterange);
    whiterange->hide();

    //text speed
    whitespeed = new QGraphicsTextItem;
    whitespeed->setPlainText(QString("Shoot Delay: ") + QString::number(white->shoot_speed));
    whitespeed->setDefaultTextColor(Qt::black);
    whitespeed->setFont(QFont("times",12));
    whitespeed->setPos(750,324);
    scene->addItem(whitespeed);
    whitespeed->hide();

    //delete added tower
    scene->removeItem(white);
    delete white;

    /**************************************/
    /*          BLACK Tower               */
    /**************************************/

    //create Tower
    BlackTower *black = new BlackTower();
    scene->addItem(black);
    black->setPos(0,0);

    costBlackTower= black->tower_cost;

    //text cost under icon
    blackcost_1 = new QGraphicsTextItem;
    blackcost_1->setPlainText(QString("Cost: ") + QString::number(black->tower_cost));
    blackcost_1->setDefaultTextColor(Qt::black);
    blackcost_1->setFont(QFont("times",10));
    blackcost_1->setPos(835,226);
    scene->addItem(blackcost_1);

    //text damage
    blackdamage = new QGraphicsTextItem;
    blackdamage->setPlainText(QString("Damage: ") + QString::number(black->damage));
    blackdamage->setDefaultTextColor(Qt::black);
    blackdamage->setFont(QFont("times",12));
    blackdamage->setPos(750,260);
    scene->addItem(blackdamage);
    blackdamage->hide();

    //text range
    blackrange = new QGraphicsTextItem;
    blackrange->setPlainText(QString("Range: ") + QString::number(black->SCALE_FACTOR));
    blackrange->setDefaultTextColor(Qt::black);
    blackrange->setFont(QFont("times",12));
    blackrange->setPos(750,292);
    scene->addItem(blackrange);
    blackrange->hide();

    //text speed
    blackspeed = new QGraphicsTextItem;
    blackspeed->setPlainText(QString("Shoot Delay: ") + QString::number(black->shoot_speed));
    blackspeed->setDefaultTextColor(Qt::black);
    blackspeed->setFont(QFont("times",12));
    blackspeed->setPos(750,324);
    scene->addItem(blackspeed);
    blackspeed->hide();

    //delete added tower
    scene->removeItem(black);
    delete black;

    global_timer->stop();
    disconnect(global_timer,SIGNAL(timeout()),this,SLOT(createtowers()));

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
    if(global_timer->isActive()){//checks if the game is paused

        if(cursor){
            if(building){
            cursor->setPos((event->pos().x()-18),(event->pos().y())-18);
            building->setPos((event->pos().x()-18),(event->pos().y())-18);
            }
        }
    }
}

void Game::mousePressEvent(QMouseEvent *event){
    if((building)&&(global_timer->isActive())){

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
            if((temp_gridpoint->occupied==0) && (money->getMoney()>=building->tower_cost)){    //check gridpoint is free and enough money
                temp_gridpoint->occupied=1;
                building->setPos((temp_gridpoint->pos().x()-12),(temp_gridpoint->pos().y()-12));
                building->find_targetpoints();
                building->attack_area->hide();
                building->TowersGridpoint=temp_gridpoint;
                money->decrease(building->tower_cost);    //decrease money
                scene->removeItem(cursor);
                delete cursor;
                cursor = nullptr;
                building = nullptr;

                if(keepBuilding){
                    switch(selectTower){
                        case 1:
                              bkt->buildTower();
                              break;

                        case 2:
                              bt->buildTower();
                              break;

                        case 3:
                              gt->buildTower();
                              break;

                        case 4:
                              rt->buildTower();
                              break;

                        case 5:
                              wt->buildTower();
                              break;

                        case 6:
                              yt->buildTower();
                              break;

                        default:
                                break;
                    }
                }
                else{
                    rt->hideText();
                    gt->hideText();
                    bt->hideText();
                    yt->hideText();
                    wt->hideText();
                    bkt->hideText();
                }


            }
        }

        has_gridpoint=false;
        return;
    }


    else{
        if(focusedTower){ //hides the range of the tower again
            focusedTower->attack_area->hide();
            focusedTower=nullptr;
        }
        QGraphicsView::mousePressEvent(event);
    }
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(keyPressEnable){
        if(event->key()==Qt::Key_T){

            keepBuilding=1;
        }

        if (event->key()==Qt::Key_Escape){
            if(building){
                scene->removeItem(building);
                scene->removeItem(cursor);
                delete building;
                delete cursor;
                building=nullptr;
                cursor=nullptr;
                focusedTower=nullptr;
                rt->hideText();
                gt->hideText();
                bt->hideText();
                yt->hideText();
                wt->hideText();
                bkt->hideText();
            }
        }

        if (event->key()==Qt::Key_Delete){
            if(focusedTower){
                focusedTower->TowersGridpoint->occupied=false;//gridpoint again free for new tower
                scene->removeItem(focusedTower);
                delete focusedTower;
                focusedTower=nullptr;
            }

        }

        if ((event->key()==Qt::Key_P)&&(!gameover)){
            if(global_timer->isActive()){
                    global_timer->stop();
                    pause = new PauseScreen();
                    scene->addItem(pause);
                    pause->setPos(0,0);
            }
            else{
                global_timer->start();
                scene->removeItem(pause);
                delete pause;

            }
        }
    }
}

void Game::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_T){
        keepBuilding=0;
    }
}




void Game::createRoad(){
    Road * build_way;
    bool has_gridpoint=false;

    {
        QGraphicsPixmapItem *finalWaypoint=new QGraphicsPixmapItem(QString(":/images/background_road_finisch.png"));
        scene->addItem(finalWaypoint);
        finalWaypoint->setPos(way_points[last_waypoint-1]);

        QList<QGraphicsItem *> items = finalWaypoint->collidingItems();
        int max = items.size();
        double closest_dist = 5000;

        int closest_gridpoint = 100;

        for(int fuck=0; fuck<max; fuck++){
            Gridpoint *temp_gridpoint = dynamic_cast<Gridpoint *>(items[fuck]);
            if(temp_gridpoint){
                has_gridpoint=true;

                QLineF ln(way_points[last_waypoint],items[fuck]->pos());

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
                finalWaypoint->setPos((temp_gridpoint->pos().x()-12),(temp_gridpoint->pos().y()-12));
                build_way = new Road();
                scene->addItem(build_way);
            }
        }

    }




    for(int count=1;count<last_waypoint;count++){

        build_way->setPos(way_points[count]);
        QList<QGraphicsItem *> items = build_way->collidingItems();
        int max = items.size();
        double closest_dist = 5000;

        int closest_gridpoint = 100;

        for(int fuck=0; fuck<max; fuck++){
            Gridpoint *temp_gridpoint = dynamic_cast<Gridpoint *>(items[fuck]);
            if(temp_gridpoint){
                has_gridpoint=true;

                QLineF ln(way_points[count],items[fuck]->pos());

                if(ln.length() < closest_dist){
                    closest_dist = ln.length();
                    closest_gridpoint = fuck;
                }
            }
        }

        if(has_gridpoint){

            Gridpoint *temp_gridpoint = dynamic_cast<Gridpoint *>(items[closest_gridpoint]);
            if(temp_gridpoint->occupied==0){
                count+=34;

                temp_gridpoint->occupied=1;
                scene->addItem(build_way);
                build_way->setPos((temp_gridpoint->pos().x()-12),(temp_gridpoint->pos().y()-12));
                build_way = new Road();
                scene->addItem(build_way);
            }
        }

        has_gridpoint=false;
    }

    if(build_way){
        scene->removeItem(build_way);
        delete build_way;
    }
}

int Game::set_waypoints(){

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

          way_points[step_counter]=position;

      }
}

void Game::creatEnemies(){

    //spawn an enemy
    if(delayCounter==0){

        switch (createEnemisState) {
        case 1:
              {
                delay_spawn_enemys=20;
                Enemy *enemy = new GreenEnemy();
                enemy->setPos((pointsToFollow[0].x()-18),(pointsToFollow[0].y()-18));
                enemy->health_enemy=enemy->health_enemy*enemy_health_boost;
                enemy->enemy_worth=enemy->enemy_worth*enemy_worth_boost;
                scene->addItem(enemy);
                enemiesSpawned += 1;
                if(enemiesSpawned==20){
                    enemiesSpawned=0;
                    createEnemisState=2;
                    delay_spawn_enemys=50;
                }
              }
            if(delay_spawn_enemys>=10) delay_spawn_enemys-=3;
              break;

        case 2:{
                delay_spawn_enemys=10;
                Enemy *enemy = new YellowEnemy();
                enemy->setPos((pointsToFollow[0].x()-18),(pointsToFollow[0].y()-18));
                enemy->health_enemy=enemy->health_enemy*enemy_health_boost;
                enemy->enemy_worth=enemy->enemy_worth*enemy_worth_boost;
                scene->addItem(enemy);
                enemiesSpawned += 1;
                if(enemiesSpawned==20){
                    enemiesSpawned=0;
                    createEnemisState=3;
                    delay_spawn_enemys=50;
                }
               }
               break;

        case 3:{
                delay_spawn_enemys=10;
                Enemy *enemy = new OrangeEnemy();
                enemy->setPos((pointsToFollow[0].x()-18),(pointsToFollow[0].y()-18));
                enemy->health_enemy=enemy->health_enemy*enemy_health_boost;
                enemy->enemy_worth=enemy->enemy_worth*enemy_worth_boost;
                scene->addItem(enemy);
                enemiesSpawned += 1;
                if(enemiesSpawned==20){
                    enemiesSpawned=0;
                    createEnemisState=4;
                    delay_spawn_enemys=50;
                }
               }
               break;
        case 4:{
                delay_spawn_enemys=15;
                Enemy *enemy = new BlueEnemy();
                enemy->setPos((pointsToFollow[0].x()-18),(pointsToFollow[0].y()-18));
                enemy->health_enemy=enemy->health_enemy*enemy_health_boost;
                enemy->enemy_worth=enemy->enemy_worth*enemy_worth_boost;
                scene->addItem(enemy);
                enemiesSpawned += 1;
                if(enemiesSpawned==20){
                    enemiesSpawned=0;
                    createEnemisState=5;
                    delay_spawn_enemys=50;
                }
               }
               break;
        case 5:{
                delay_spawn_enemys=15;
                Enemy *enemy = new VioletEnemy();
                enemy->setPos((pointsToFollow[0].x()-18),(pointsToFollow[0].y()-18));
                enemy->health_enemy=enemy->health_enemy*enemy_health_boost;
                enemy->enemy_worth=enemy->enemy_worth*enemy_worth_boost;
                scene->addItem(enemy);
                enemiesSpawned += 1;
                if(enemiesSpawned==20){
                    enemiesSpawned=0;
                    createEnemisState=6;
                    delay_spawn_enemys=50;
                }
               }
               break;
        case 6:{
                delay_spawn_enemys=15;
                Enemy *enemy = new RedEnemy();
                enemy->setPos((pointsToFollow[0].x()-18),(pointsToFollow[0].y()-18));
                enemy->health_enemy=enemy->health_enemy*enemy_health_boost;
                enemy->enemy_worth=enemy->enemy_worth*enemy_worth_boost;
                scene->addItem(enemy);
                enemiesSpawned += 1;
                if(enemiesSpawned==20){
                    enemy_worth_boost=enemy_worth_boost*1.6;
                    enemy_health_boost=enemy_health_boost*1.8;
                    enemiesSpawned=0;
                    createEnemisState=1;
                    delay_spawn_enemys=50;
                }
               }
               break;

        case 7:{
                delay_spawn_enemys=2;
                enemiesSpawned += 1;
                if(enemiesSpawned==20){
                    enemy_worth_boost=1;
                    enemy_health_boost=1;
                    enemiesSpawned=0;
                    createEnemisState=1;
                    delay_spawn_enemys=50;
                    global_timer->stop();
                }
               }
               break;


        default:
            break;
        }

    }

    delayCounter++;

    if(delayCounter>=delay_spawn_enemys){
        delayCounter=0;
    }

}

/**********************************************/
/* We call it Anita, the brain of the game =) */
/**********************************************/

#ifndef GAME
#define GAME

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "tower.h"
#include "score.h"
#include "health.h"
#include <QTimer>
#include "enemy_list_element.h"
#include "road.h"
#include "money.h"
#include "pausescreen.h"
#include "buildredtowericon.h"
#include "buildbluetowericon.h"
#include "buildgreentowericon.h"
#include "buildblacktowericon.h"
#include "buildwhitetowericon.h"
#include "buildyellowtowericon.h"
#include <QGraphicsTextItem>
#include "redtower.h"


class Game: public QGraphicsView{
    Q_OBJECT

public:
    //member functions
    Game();//constructor
    void setCursor(QString filename);//function to connect the towericon to the cursor
    void mouseMoveEvent(QMouseEvent *event); //passes the actual cursor-position to the towericon
    void mousePressEvent(QMouseEvent *event);//build the tower on the actual cordinates
    void keyPressEvent(QKeyEvent*event);

    BuildRedTowerIcon * rt;
    BuildGreenTowerIcon * gt;
    BuildBlueTowerIcon * bt;
    BuildBlackTowerIcon * bkt;
    BuildWhiteTowerIcon * wt;
    BuildYellowTowerIcon * yt;

    //member attributes
    QGraphicsScene *scene;//field of the game
    QGraphicsPixmapItem *cursor;//for the towericon
    Tower * building; // tower pointer for building new towers
    Score *score;
    Health *health;
    Money *money;
    QList<QPointF> pointsToFollow; // defines the path of the enemys. list of key points were they change direction
    QList<QPointF> field_menu;//Points to split scene in play field an menu
    QTimer * global_timer = new QTimer(this); //global timer used for every delay

    double direction[40][2];//defines direction betweeen points to follow
    QPointF way_points [10000]; //list of posible positions of the enemies
    int last_waypoint; //last posible position for the enemies
    enemy_list_element enemy_list[500]; //list of all enemies on the screen
    int last_enemy=-1; //last enemy in the list

    Tower * focusedTower; //is the address of the focused tower.

    int costRedTower;
    int costBlackTower;
    int costBlueTower;
    int costGreenTower;
    int costWhiteTower;
    int costYellowTower;

    QGraphicsTextItem *redcost_1;
    QGraphicsTextItem *reddamage;
    QGraphicsTextItem *redrange;
    QGraphicsTextItem *redspeed;

    QGraphicsTextItem *greencost_1;
    QGraphicsTextItem *greendamage;
    QGraphicsTextItem *greenrange;
    QGraphicsTextItem *greenspeed;

    QGraphicsTextItem *bluecost_1;
    QGraphicsTextItem *bluedamage;
    QGraphicsTextItem *bluerange;
    QGraphicsTextItem *bluespeed;

    QGraphicsTextItem *yellowcost_1;
    QGraphicsTextItem *yellowdamage;
    QGraphicsTextItem *yellowrange;
    QGraphicsTextItem *yellowspeed;

    QGraphicsTextItem *whitecost_1;
    QGraphicsTextItem *whitedamage;
    QGraphicsTextItem *whiterange;
    QGraphicsTextItem *whitespeed;

    QGraphicsTextItem *blackcost_1;
    QGraphicsTextItem *blackdamage;
    QGraphicsTextItem *blackrange;
    QGraphicsTextItem *blackspeed;

    bool keyPressEnable = true;

private:
    int delay_spawn_enemys=20; //time between spawning the enemys
    int set_waypoints();    //sets the position of the enemy points in the way_point[] array
    void createRoad(); //builds the road
    int enemiesSpawned; //counts the number of spwaned enemys
    int maxNumberOfEnemies; //max. enemies that could be spawned
    char createEnemisState=1;
    int delayCounter=0;
    double enemy_health_boost=1;
    double enemy_worth_boost=1;
    PauseScreen * pause; //picture when the game is paused


public slots:
    void creatEnemies();  //funciton who spawns the enemies

private slots:
    void createtowers();

};

#endif // GAME


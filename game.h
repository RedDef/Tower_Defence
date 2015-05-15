#ifndef GAME
#define GAME

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "tower.h"
#include "score.h"
#include "health.h"
#include <QTimer>
#include "enemy_point.h"
#include "road.h"

/*
 basicliy the brain of the game

 * */

class Game: public QGraphicsView{
    Q_OBJECT
public:
    //member functions
    Game();
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    //member attributes
    QGraphicsScene *scene;
    QGraphicsPixmapItem *cursor;
    Tower * building; // tower pointer for building new towers
    Score *score;
    Health *health;
    int enemiesSpawned; //counts the number of spwaned enemys
    int maxNumberOfEnemies;
    QList<QPointF> pointsToFollow; // defines the path of the enemys. list of points were the change direction
    QList<QPointF> field_menu;
    QTimer * move_timer = new QTimer(this); //global timer used for every delay

    double direction[40][2];
    enemy_point way_points [10000]; // list of posible positions of the enemys
    int last_waypoint; //last posible position for the enemys
    int enemy_list[500]; //list of all enemys on the screen
    int last_enemy=-1; //last enemy in the list




private:
    int delay_spawn_enemys=0; //time between spawning the enemys
    int set_waypoints();    //sets the position of the way_point array
    void createRoad(); //builds the road
    void createEnemies(int numberOfEnemies); //sets how many enemys are created
    int gPoint_x;   //used for creating the gridpoints
    int gPoint_y;   //used for creating the gridpoints


public slots:
    void spawnEnemy();  //spawns the enemys

};

#endif // GAME


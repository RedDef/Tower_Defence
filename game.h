#ifndef GAME
#define GAME

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "tower.h"
#include <QTimer>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    //member functions
    Game();
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void createEnemies(int numberOfEnemies);
    void createRoad();

    //member attributes
    QGraphicsScene *scene;
    QGraphicsPixmapItem *cursor;
    Tower * building;
    QTimer * spawnTimer;
    int enemiesSpawned;
    int maxNumberOfEnemies;
    QList<QPointF> pointsToFollow;
    QList<QPointF> field_menu;
    int gPoint_x;
    int gPoint_y;
    QTimer * move_timer = new QTimer(this);

    double direction[10][2];


public slots:
    void spawnEnemy();

};

#endif // GAME


#include "game.h"
#include "whalea.h"
#include <QDebug>

Game::Game(QWidget *parent){
    this->setMouseTracking(true);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,800); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1100,900);

    // start global timer
    timer = new QTimer();
    // start the timer
    timer->start(25);

}

void Game::start(){
    // test code TODO remove
    whale = new WhaleA();
    whale->drawWhale();
    whale->animateWhale();
}

void Game::mouseMoveEvent(QMouseEvent *event){
    qDebug() << "mouse detected";
    qDebug() << event->pos();
    whale->updateTargetMousePosition(event);
}

void Game::mousePressEvent(QMouseEvent *event)
{
    switch(event->button()){
        case Qt::LeftButton: {
            qDebug() << "mouse Left";
            whale->leftBarrelRoll();
            break;
        }
        case Qt::MiddleButton: {
            qDebug() << "mouse Middle";
            break;
        }
        case Qt::RightButton: {
            qDebug() << "mouse Right";
            whale->rightBarrelRoll();
            break;
        }
    }
}

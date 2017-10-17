#include "game.h"
#include "whalea.h"

Game::Game(){
    // set up the screen
    // setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // set up the scene
    scene = new QGraphicsScene();
//    scene->setSceneRect(0,0,1024,768);

    view = new QGraphicsView(scene);
//    view->setFixedSize(1024,768);
    view->show();
}

void Game::start(){
    // test code TODO remove
    whale = new WhaleA();
    whale->drawWhale(100,100);
    view->update();
}

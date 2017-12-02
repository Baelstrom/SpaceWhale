#include "game.h"
#include "whalea.h"

Game::Game(){

}

void Game::start(){
    // create a new view and a scene
    view = new QGraphicsView();
    scene = new QGraphicsScene(0, 0, 1000, 800, view);
//    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(800,600);
    view->setScene(scene);

    //Create a Whale
    WhaleA * derpina = new WhaleA();
    derpina->drawWhale();

}

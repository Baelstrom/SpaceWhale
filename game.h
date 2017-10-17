#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "whalea.h"
#include <QWidget>

class Game{
public:
    // constructors
    Game();

    // public methods
    void start();

    // public attributes
    QGraphicsScene * scene;
    QGraphicsView * view;
    WhaleA * whale;
};

#endif // GAME_H

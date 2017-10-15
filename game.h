#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "whalea.h"
#include <QWidget>

class Game: public QGraphicsView{
public:
    // constructors
    Game(QWidget * parent=NULL);

    // public methods
    void start();

    // public attributes
    QGraphicsScene * scene;
    WhaleA * whale;
};

#endif // GAME_H

#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "whalea.h"
#include <QWidget>
#include <QTimer>
#include "space.h"

class Game: public QGraphicsView{
public:
    // constructors
    Game(QWidget * parent=0);

    // public methods
    void start();
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);

    // public attributes
    QGraphicsScene * scene;
    QGraphicsView * view;
    WhaleA * whale;
    Space * space;
    QTimer * timer;
};

#endif // GAME_H

#ifndef WHALEA_H
#define WHALEA_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "MyRect.h"

class WhaleA: QGraphicsRectItem
{
public:
    // constructor
    WhaleA();

    // getters / setters
    QList<QGraphicsRectItem*>  getWhale();

    // public methods
    void drawWhale(int x, int y);
    void keyPressEvent(QKeyEvent * event);

private:
    QList<QGraphicsRectItem*> whale;
    QGraphicsRectItem * head;
};

#endif // WHALEA_H

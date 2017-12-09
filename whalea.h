#ifndef WHALEA_H
#define WHALEA_H

#include <QObject>
#include <QList>
#include <QVector>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QMouseEvent>
#include "whaleslice.h"
class WhaleA: public QObject
{
    Q_OBJECT
public:
    // constructor
    WhaleA();

    // public methods
    void drawWhale();
    void animateWhale();

public slots:
    // public slots
    void move();
    void updateTargetMousePosition(QMouseEvent * event);

private:

    // whale variables
    WhaleSlice * head;
    QVector<WhaleSlice*> whale;
    WhaleSlice ** whaleArray;
    bool  reachedPosition;
    QPointF * targetPosition;

    // everything to do with history
    QVector<float> dxHistory;
    QVector<float> dyHistory;
    float * dxHistoryArray;
    float * dyHistoryArray;

    // private functions
    float getVelocity(float distance);
    float getNewCoords(float w2, float w1, float velocity);
    void shiftHistory();
};

#endif // WHALEA_H

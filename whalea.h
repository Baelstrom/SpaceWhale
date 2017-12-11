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
    void leftBarrelRoll();
    void rightBarrelRoll();

public slots:
    // public slots
    void move();
    void updateTargetMousePosition(QMouseEvent * event);


private:

    // whale variables
    WhaleSlice * head;
    QList<WhaleSlice*> whale;
    bool  reachedPosition;
    QPointF * targetPosition;

    // everything to do with history
    QVector<float> dxHistory;
    QVector<float> dyHistory;
    QVector<float> tHistory;
    float * dxHistoryArray;
    float * dyHistoryArray;
    float * tHistoryArray;
    qreal  currentRotation;


    // private functions
    float getVelocity(float distance);
    float getNewCoords(float w2, float w1, float velocity);
    void shiftHistory();
    bool isLeftBarrelRoll;
    bool isRightBarrelRoll;
    void barrelRoll();
    bool isHolySmokes;
};

#endif // WHALEA_H

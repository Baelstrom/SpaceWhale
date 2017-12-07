#ifndef WHALEA_H
#define WHALEA_H

#include <QObject>
#include <QList>
#include <QVector>
#include <QGraphicsRectItem>
#include <QMouseEvent>
class WhaleA: public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    // constructor
    WhaleA();

    // public methods
    void drawWhale();
    void animateWhale();

public slots:
    void move();
    void updateTargetMousePosition(QMouseEvent * event);
private:
    // private variables
    QGraphicsRectItem * head;
    QVector<float> history;
    bool  reachedPosition;
    QVector<QGraphicsRectItem*> whale;
    QGraphicsRectItem ** whaleArray;
    QPointF * targetPosition;

    // private functions
    float getVelocity(float distance);
    float getNewCoords(float w2, float w1, float velocity);
};

#endif // WHALEA_H

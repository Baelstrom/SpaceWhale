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
    // public slots
    void move();
    void updateTargetMousePosition(QMouseEvent * event);

private:

    // whale variables
    QGraphicsRectItem * head;
    QVector<QGraphicsRectItem*> whale;
    QGraphicsRectItem ** whaleArray;
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

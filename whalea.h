#ifndef WHALEA_H
#define WHALEA_H

#include <QObject>
#include <QList>
#include <QVector>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>

class WhaleA: public QObject,public QGraphicsPixmapItem
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
    QGraphicsPixmapItem * head;
    QVector<QGraphicsPixmapItem*> whale;
    QGraphicsPixmapItem ** whaleArray;
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

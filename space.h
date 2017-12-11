#ifndef SPACE_H
#define SPACE_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QMouseEvent>


class Space : public QObject
{
    Q_OBJECT
public:
    explicit Space(QObject *parent = nullptr); 
    void animateStarfield();
    QGraphicsRectItem * star;
signals:

public slots:
    void updateTargetMousePosition(QMouseEvent * event);
    void starry();
private:
    QPointF * targetPosition;
    float getRandomNumFromRange(float start, float end);
    int height;
    int width;
    float velocity;
};

#endif // SPACE_H

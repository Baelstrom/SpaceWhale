#include "space.h"
#include "game.h"
#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <QDebug>
extern Game * game;

Space::Space(QObject *parent) : QObject(parent)
{
    targetPosition = new QPointF();
    targetPosition->setX(50);
    targetPosition->setY(50);
    width = game->scene->width();
    height = game->scene->height();
    star = new QGraphicsRectItem;
    star->setRect(0,0,2,2);
    star->setPos(width/2,height/2);

    game->scene->addItem(star);

    velocity = 0.1 * 0.3 ;
}

void Space::animateStarfield()
{
    connect(game->timer,SIGNAL(timeout()),this,SLOT(starry()));

}

void Space::starry()
{

    // do while !outOfBounds
    QPointF currentPosition = star->pos();
    QPointF * mouseCoords = targetPosition;

    float  x = currentPosition.x();
    float  y = currentPosition.y();

    qDebug() << "initial";
    qDebug() << x;
    qDebug() << y;

    float  dx = mouseCoords->x();
    float  dy = mouseCoords->y();


    qDebug() << "before debug"                ;
    // do transformation
    x = x + ( x - dx ) * velocity;
    y = y + ( y- dy ) * velocity;
    qDebug() << "afterDebug";
    qDebug() << x;
    qDebug() << y;


    // check if out of bounds
    if ( x > (float)width || x < 0 || y > (float)height || y < 0) {
        x = width/2;
        y = height/2;
    }

    qDebug() << "dx dy";
    qDebug() << dx ;
    qDebug() << dy ;
    qDebug() << "x y";
    qDebug() << x;
    qDebug() << y;
    star->setPos(x,y);





}

void Space::updateTargetMousePosition(QMouseEvent *event){
    QPointF position = event->pos();
    targetPosition->setX(position.x());
    targetPosition->setY(position.y());
}

float Space::getRandomNumFromRange(float start, float end) {
    float random = (float)rand() * end + start;
    return random;
}

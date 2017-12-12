#include "space.h"
#include "game.h"
#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QDebug>
extern Game * game;

Space::Space(QObject *parent) : QObject(parent)
{
    targetPosition = new QPointF();
    numberOfStars = 50;
    width = game->scene->width();
    height = game->scene->height();
    targetPosition->setX(50);
    targetPosition->setY(50);
    velocity = 0.1 * 0.2 ;


    for(int i = 0; i < numberOfStars; i++){
        QGraphicsEllipseItem * star = new QGraphicsEllipseItem();
        star->setBrush(Qt::white);
        star->setRect(0,0,3,3);
        float randomX = getRandomNumFromRange(0,width);
        float randomY = getRandomNumFromRange(0,height);
        star->setPos(randomX,randomY);
        starfield.append(star);
        game->scene->addItem(star);
    }

    qDebug() << starfield[1]->pos();
}

void Space::animateStarfield()
{
    connect(game->timer,SIGNAL(timeout()),this,SLOT(starry()));
}

void Space::starry()
{

    QPointF * mouseCoords = targetPosition;
    float  dx = mouseCoords->x();
    float  dy = mouseCoords->y();

    for(int i = 0; i<numberOfStars; i++){
        qDebug() << "here";
        QGraphicsEllipseItem * starItem = starfield[i];
        qDebug()<< starItem;
        QPointF currentPosition = starItem->pos();

        float x = currentPosition.x();
        float y = currentPosition.y();

        x = x + ( x - dx ) * velocity;
        y = y + ( y- dy ) * velocity;

        if ( x > (float)width || x < 0 || y > (float)height || y < 0) {
            x = getRandomNumFromRange(0,width);
            y = getRandomNumFromRange(0,height);
        }

        starItem->setPos(x,y);
    }

}

void Space::updateTargetMousePosition(QMouseEvent *event){
    QPointF position = event->pos();
    targetPosition->setX(position.x());
    targetPosition->setY(position.y());
}

float Space::getRandomNumFromRange(float start, float end) {
    float random = float(rand() % (int)end) + start;
    return random;
}

#include "whalea.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "game.h"
#include <QTimer>
#include <QDebug>
#include <QList>
#include <QVector>
#include <QMouseEvent>

extern Game* game;

WhaleA::WhaleA(): QObject(),  QGraphicsRectItem(){
    QVector<QGraphicsRectItem*> whale(4);
    targetPosition = new QPointF();
    targetPosition->setX(10);
    qDebug() << "runs here";
    targetPosition->setY(10);
}

void WhaleA::drawWhale(){
    // This function adds all the slices of the whale to the scene


    // number of slices
    int numOfRects = 3;

    // interator to create them
    for (int i = 0; i < numOfRects; i++ ) {

        // create the rect
        QGraphicsRectItem * slice = new QGraphicsRectItem();

        // set the size of the rect
        slice->setRect(0,0,100,100);

        // set the position
        slice->setPos(i*100,i*100);
        qDebug() << "created";
        qDebug() << i;
        // append to list of whale slices
        whale.append(slice);

        // add to scene
        game->scene->addItem(slice);


    }
    whaleArray = whale.data();

    // set the head of the whale to be focusable so that we can move it
//    head = whale[0];

    head =whale.first();
    head->setFlag(QGraphicsItem::ItemIsFocusable);
    head->setFocus();

}




void WhaleA::animateWhale()
{
    connect(game->timer,SIGNAL(timeout()),this,SLOT(move()));
}

void WhaleA::move(){
//    for(int i = 0; i < whale.count(); i++ ){
//         qDebug() << "animating...";
//         whale[i]->setPos(x()-10,y()-10);

//    }
//  head->setPos(position.x(),position.y()+10);
    QPointF  currentPosition = head->pos();

    reachedPosition = false;
    QPointF * finalPosition = targetPosition;

    float x2 = finalPosition->x();

    float y2 = finalPosition->y();

//      while(!reachedPosition){
        // check distance between target position and current position
        // based on if conditions, set velocity
        // move the square towards that position
        // formula for distance is = sqrt( pow((a1 - at), 2) + pow((b1 - b2, 2))

        // get variables first.

        float x1 = currentPosition.x();
        float y1 = currentPosition.y();

        // find distance
        float distance = sqrt( pow((x2-x1), 2) + pow((y2-y1), 2));

        // is x2 greater than x1?
        //   if true, then subract velocity from x1
        //   else add velocity from x1
        // is y2 greater than y1?
        //   same logic except for y

        float velocity = getVelocity(distance);
        float nx = getNewCoords(x2,x1,velocity);
        float ny = getNewCoords(y2,y1,velocity);

        head->setPos(nx,ny);



        // move by values found above.

        // first calculate where we're moving
        // replace x+1 with history
        //

        // move head, then move body
//                qDebug() << "here";
//         qDebug() << "created2";

        for(int i = 0; i < 3; i++) {
        QGraphicsRectItem * arrayItem = whaleArray[i];

        arrayItem->setPos(x()+nx+25*i,y()+ny+25*i);
        whaleArray[i] = arrayItem;
//        qDebug() << "Array Item Updated";
//        qDebug() <<  whaleArray[i];
        }

//      }

}

float WhaleA::getVelocity(float distance){
    float velocity;

    if (distance > 300) {
        velocity = 9;
    } else if (distance >= 200) {
        velocity = 7;
    } else if (distance >= 100) {
        velocity = 5;
    } else if (distance >= 50) {
        velocity = 3;
    } else if (distance >= 1) {
        velocity = 1;
    } else if (distance == 0) {
        velocity = 0;
    }

    return velocity;
}

float WhaleA::getNewCoords(float w2, float w1, float velocity){
    if (w2 > w1) {
        return w1 + velocity;
    } else if (w2 < w1) {
        return w1 - velocity;
    } else if (w2 == w1) {
        reachedPosition = true;
        return w1;
    }
}

void WhaleA::updateTargetMousePosition(QMouseEvent *event){
    QPoint position = event->pos();

    targetPosition->setX(position.x());
    targetPosition->setY(position.y());
}

//void WhaleA::addHistory(float velocity){

//}

//QPointF WhaleA::randomPoint(){
//    int random_number = rand() % 700;

//}

// the purpose of this function is to register the plsceneayers movement actions
// and register them to the head of the whale




#include "whalea.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "game.h"
#include <QTimer>
#include <QDebug>
#include <QList>
#include <QVector>
#include <QMouseEvent>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <whaleslice.h>

extern Game* game;

WhaleA::WhaleA(): QObject(){
    QList<WhaleSlice*> whale;
    targetPosition = new QPointF();
    targetPosition->setX(0);
    targetPosition->setY(0);
    isLeftBarrelRoll = false;
    isRightBarrelRoll = false;
    isHolySmokes = false;
}

void WhaleA::drawWhale(){
//    // This function adds all the slices of the whale to the scene


    // number of slices
    int numOfRects = 44;

    // iterator to create them
    for (int i = 0; i < numOfRects; i++ ) {

        // get the image
        QString index = QString::number(i);
        QString path = ":/whaleSlices/Slices/";
        path.append(index);
        path.append(".png");
        WhaleSlice * slice = new WhaleSlice(path);
        // set the position
        slice->setPos(i*100,i*100);
        slice->setTransformOriginPoint(90,140);
        qDebug() << "created";
        qDebug() << i;
        // append to list of whale slices
        whale.append(slice);

        // add to scene
        game->scene->addItem(slice);
    }

    // iterator to create history array
    for (int i = 0; i < numOfRects; i++){
        dxHistory.append(0.0);
        dyHistory.append(0.0);
        tHistory.append(0.0);
    }

    // change history array and whale array into workable array objects
    dxHistoryArray = dxHistory.data();
    dyHistoryArray = dyHistory.data();
    tHistoryArray = tHistory.data();

    // get the head and make that focusable
    head = whale.first();
    head->setFlag(QGraphicsItem::ItemIsFocusable);
    head->setFocus();

}




void WhaleA::animateWhale()
{
    connect(game->timer,SIGNAL(timeout()),this,SLOT(move()));
}

void WhaleA::move(){

    QPointF  currentPosition = head->pos();
    QPointF * finalPosition = targetPosition;
    QTransform transformation;
    transformation.rotate(1.0);



    float x2 = finalPosition->x() - 133;
    float y2 = finalPosition->y() - 177;

    float x1 = currentPosition.x();
    float y1 = currentPosition.y();

    // find distance
    float xDistance = sqrt(pow(x2-x1,2));
    float yDistance = sqrt(pow(y2-y1,2));

    float velocity = getVelocity(xDistance);
    float nx = getNewCoords(x2,x1,velocity);
    velocity = getVelocity(yDistance);
    float ny = getNewCoords(y2,y1,velocity);


    // first shift the history array one step to the right
    // then update 0th position of history array to be the new positions derived from calculations for velocity etc..
    // then iterate over the whale array object and apply transformations where history[i].pos == whale[i].pos

    // shift history
    shiftHistory();

    // update head of the array to be the new co ordinates
    dxHistoryArray[0] = nx;
    dyHistoryArray[0] = ny;
    barrelRoll();


    // iterate over whale object and apply transformations
    for(int i = 0; i < 44; i++) {
        WhaleSlice * arrayItem = whale[i];

        // apply movement
        nx = dxHistoryArray[i];
        ny = dyHistoryArray[i];

        // check for barrelRoll
        // if lBarrelRoll == true
        arrayItem->setRotation(tHistoryArray[i]);
        arrayItem->setPos(nx,ny);
    }




}

float WhaleA::getVelocity(float distance){
    float velocity;

    if (distance > 300) {
        velocity = 15;
    } else if (distance >= 200) {
        velocity = 10;
    } else if (distance >= 100) {
        velocity = 7;
    } else if (distance >= 50) {
        velocity = 5;
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
        return w1;
    }
}

void WhaleA::updateTargetMousePosition(QMouseEvent *event){
    QPoint position = event->pos();
    targetPosition->setX(position.x());
    targetPosition->setY(position.y());
}

void WhaleA::leftBarrelRoll()
{
    if(!isRightBarrelRoll){
        isLeftBarrelRoll = true;
        qDebug() << isLeftBarrelRoll;
    }
}

void WhaleA::rightBarrelRoll()
{
    if(!isLeftBarrelRoll){
        isRightBarrelRoll = true;
        qDebug() << isRightBarrelRoll;
    }
}

void WhaleA::shiftHistory(){
    int arraySize = 44;

    for(int i = arraySize - 1; i > 0; i--){
        dxHistoryArray[i] = dxHistoryArray[i-1];
        dyHistoryArray[i] = dyHistoryArray[i-1];
        tHistoryArray[i] = tHistoryArray[i-1];
    }


}

void WhaleA::barrelRoll() {

    if(isLeftBarrelRoll && tHistoryArray[0] != -350){
        //        slice->setRotation(currentRotation - 5);
        tHistoryArray[0] = tHistoryArray[0] - 10;
        qDebug() << "fired left barrel roll head update";
    } else if (isLeftBarrelRoll && tHistoryArray[0] == -350) {
        tHistoryArray[0] = 0;
        isLeftBarrelRoll = false;
    }

    if(isRightBarrelRoll && tHistoryArray[0] != 350) {
        //       slice->setRotation(currentRotation + 5);
        tHistoryArray[0] = tHistoryArray[0] + 10;
        qDebug() << "fired right barrel roll head update";
    } else if (isRightBarrelRoll && tHistoryArray[0] == 350) {
        tHistoryArray[0] = 0;
        isRightBarrelRoll = false;
    }

    qDebug() << tHistoryArray[0];
}

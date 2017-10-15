#include "whalea.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "game.h"
#include <QDebug>
extern Game* game;

WhaleA::WhaleA()
{

}

QList<QGraphicsRectItem *> WhaleA::getWhale()
{
    return whale;
}


void WhaleA::drawWhale(int x, int y){
    // This function adds all the slices of the whale to the scene


    // number of slices
    size_t numOfRects = 3;

    // interator to create them
    for (size_t i = 0; i < numOfRects; i++ ) {

        // create the rect
        QGraphicsRectItem * slice = new QGraphicsRectItem();

        // set the size of the rect
        slice->setRect(0,0,100,100);

        // set the position
        slice->setPos(500,500);

        // append to list of whale slices
        whale.append(slice);

        // add to scene
        game->scene->addItem(slice);

        qDebug() << "created";
    }

    // set the head of the whale to be focusable so that we can move it
    head = whale.first();
    head->setFlag(QGraphicsItem::ItemIsFocusable);
    head->setFocus();
}


// the purpose of this function is to register the players movement actions
// and register them to the head of the whale
void WhaleA::keyPressEvent(QKeyEvent * event){
    switch (event->key()) {
        case Qt::Key_Left : {
            head->setPos(x()-10,y());
            qDebug() << "left";
            break;
        }
        case Qt::Key_Right : {
            head->setPos(x()-10,y());
            qDebug() << "right";
            break;
        }
        case Qt::Key_Up : {
            head->setPos(x()-10,y());
            qDebug() << "up";
            break;
        }
        case Qt::Key_Down : {
            head->setPos(x()-10,y());
            qDebug() << "down";
            break;
        }
    }
}

#include "whalea.h"
#include <QGraphicsRectItem>
#include "MyRect.h"
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


void WhaleA::drawWhale(){
    // This function adds all the slices of the whale to the scene
    qDebug() << "inside drawWhale()";

    // number of slices
    size_t numOfRects = 3;
    qDebug() << "init noOf Rects";
    // interator to create them
    for (size_t i = 1; i < numOfRects+1; i++ ) {
        qDebug() << "inside Loop";
        // create the rect
        QGraphicsRectItem * slice = new QGraphicsRectItem();
        qDebug() << "created slice";
        // set the size of the rect and the position
        slice->setRect(20*i,20*i,100,100);
        qDebug() << "set my rect";
//        // set the position
//        slice->setPos(100*i,100*i);

        // append to list of whale slices
        whale.append(slice);
        qDebug() << "appended";
        // add to scene
        game->scene->addItem(slice);
        qDebug() << "created";
    }

    // set the head of the whale to be focusable so that we can move it
    head = whale.first();
    head->setFlag(QGraphicsItem::ItemIsFocusable);
    head->setFocus();
    qDebug() << head;
}


// the purpose of this function is to register the players movement actions
// and register them to the head of the whale
void WhaleA::keyPressEvent(QKeyEvent * event){
    qDebug() << "pressed";
    switch (event->key()) {
        case Qt::Key_Left : {
            this->setPos(x()-10,y());
            qDebug() << "left";
            break;
        }
        case Qt::Key_Right : {
            this->setPos(x()+10,y());
            qDebug() << "right";
            break;
        }
        case Qt::Key_Up : {
            this->setPos(x(),y()-10);
            qDebug() << "up";
            break;
        }
        case Qt::Key_Down : {
            this->setPos(x(),y()+10);
            qDebug() << "down";
            break;
        }
    }

}

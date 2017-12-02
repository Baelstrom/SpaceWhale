#include "MyRect.h"
#include <QKeyEvent>
#include "whalea.h"
#include <QDebug>

void MyRect::keyPressEvent(QKeyEvent * event){
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

// --- Notes concerning Movement ---
// create an array of rectangles that represent the player
// what are the properties of each array Item?
// has a size / shape / color. But more importantly a relative position to element 0. ( the head )
// relative positions are defined on app load.
// on moving the head. The relative position of element x needs to move to that same location.
// with the caveat that each element x needs to follow the same path as element 0
// so we have a pathHistory for element 0

// What happens on move() ?
// move element 0 to new pos( hexBoard = new HexBoard();    )
// set moving to true
// push pos() to pathHistory array
// while(isPlayerMoving == true && isBodyMoving == true)
//  forEach path in pathHistory
//   get pos from pathHistory
//    < velocity stuff }>
//      find distance between pathHistory pos an element x pos
//       distance = SQRT( (x2-x1)^2 + (y2-y1)^2 )
//      if (distance >= 7)
//        if difference between x2 - x1 = positive then subtract. else add
//          dx and dy are = +/- 5
//      else if (distance < 7 && distance > 3 )
//        if difference between x2 - x1 = positive then subtract. else add
//          dx and dy are =  +/- 3
//      else
//        set elementx, x and y =  pos.x and pos,y
//
// if (!isBodyMoving) {
//   set state to idle animation
//}
//

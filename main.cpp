#include <QApplication>
#include "game.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "MyRect.h"


Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    game = new Game();
//    game->start();

    QGraphicsScene * scene = new QGraphicsScene();
//    scene->setSceneRect(0,0,1024,768);
       // create an item to add to the scene
       MyRect * rect = new MyRect();
       rect->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels

       // add the item to the scene
       scene->addItem(rect);

       // make rect focusable
       rect->setFlag(QGraphicsItem::ItemIsFocusable);
       rect->setFocus();

       // create a view to visualize the scene
       QGraphicsView * view = new QGraphicsView(scene);
       view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
       view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

       // show the view
//       view->setSceneRect(0,0,1024,768);
       view->show();
       view->setFixedSize(800,600);
       scene->setSceneRect(0,0,800,600);

       rect->setPos(view->width()/2,view->height() - rect->rect().height());



    return a.exec();
}

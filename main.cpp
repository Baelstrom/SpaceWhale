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
//    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    game = new Game();
    game->start();

    // Create a view and a scene
//    QGraphicsView * view = new QGraphicsView();
//    QGraphicsScene * scene = new QGraphicsScene(0, 0, 1000, 800, view);
//    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Add A Rectangle to the scene
//    MyRect * rect = new MyRect();
//    rect->setRect(0,0,100,100);
//    scene->addItem(rect);
//    rect->setFlag(QGraphicsItem::ItemIsFocusable);
//    rect->setFocus();


    // set scene in view
//    view->show();
//    view->setFixedSize(800,600);
//    view->setScene(scene);

//    rect->setPos(view->width()/2,view->height() - rect->rect().height());

    return a.exec();
}

#include <QApplication>
#include "game.h"

Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOverrideCursor(Qt::BlankCursor);
    game = new Game();
    game->show();
    game->start();

    return a.exec();
}

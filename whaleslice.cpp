#include "whaleslice.h"


WhaleSlice::WhaleSlice(QString path): QObject(),  QGraphicsPixmapItem()
{
    setPixmap(QPixmap(path));
}

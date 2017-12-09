#ifndef WHALESLICE_H
#define WHALESLICE_H

#include <QGraphicsPixmapItem>
#include <qobject.h>



class WhaleSlice: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    WhaleSlice(QString path);
};

#endif // WHALESLICE_H

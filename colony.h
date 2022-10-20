#ifndef COLONY_H
#define COLONY_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class colonyVisual
{
public:
    explicit colonyVisual();
    ~colonyVisual();


    QPixmap* mPixmap;
    QGraphicsPixmapItem* mPixitem;

private:

};

#endif // COLONY_H

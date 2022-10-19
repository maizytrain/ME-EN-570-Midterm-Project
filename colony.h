#ifndef COLONY_H
#define COLONY_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class ant;

class colony
{
public:
    explicit colony();
    ~colony();


    QPixmap* mPixmap;
    QGraphicsPixmapItem* mPixitem;

private:
    ant *firstAnt{nullptr};

};

#endif // COLONY_H

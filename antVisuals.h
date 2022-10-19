#ifndef ANT_H
#define ANT_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "antlogic.h"

class antVisual
{
public:
    explicit antVisual();
    ~antVisual();

    QPixmap* mPixmap;
    QGraphicsPixmapItem* mPixItem;

private:
    antLogic* mAntLogic{nullptr};
};

#endif // ANT_H

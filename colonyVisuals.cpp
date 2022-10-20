#include "colonyVisuals.h"

colonyVisual::colonyVisual()
{
    QPixmap tempPixmap(":/images/Anthill");
    mPixmap = new QPixmap(tempPixmap.scaledToHeight(100));
    mPixitem = new QGraphicsPixmapItem(*mPixmap);
}

colonyVisual::~colonyVisual()
{
    delete mPixmap;
    delete mPixitem;
}

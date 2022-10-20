#include "antVisuals.h"

antVisual::antVisual()
{
    QPixmap tempPixmap(":/images/antpic.png");
    mPixmap = new QPixmap(tempPixmap.scaledToHeight(30));
    mPixItem = new QGraphicsPixmapItem(*mPixmap);
}

antVisual::~antVisual()
{
    delete mPixmap;
    delete mPixItem;
}

#include "antVisuals.h"
#include "qgraphicsscene.h"

antVisual::antVisual()
{
    QPixmap tempPixmap(":/images/antpic.png");
    mPixmap = new QPixmap(tempPixmap.scaledToHeight(64));
    mPixItem = new QGraphicsPixmapItem(*mPixmap);
}

antVisual::~antVisual()
{
    delete mPixmap;
    delete mPixItem;
}

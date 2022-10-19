#include "colony.h"

colony::colony()
{

    mPixmap = new QPixmap("images/Ground_Dirt_007.jpg");
    mPixitem = new QGraphicsPixmapItem(*mPixmap);

}

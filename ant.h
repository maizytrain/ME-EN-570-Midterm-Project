#ifndef ANT_H
#define ANT_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class ant
{
public:
    explicit ant();
    ~ant();


private:
    ant* nextAnt{nullptr};
    QGraphicsPixmapItem* mPixItem{nullptr};
    QPixmap* mPixmap{nullptr};
};

#endif // ANT_H

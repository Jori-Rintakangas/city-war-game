#ifndef ACTORITEM_HH
#define ACTORITEM_HH

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

namespace StudentSide
{

const int WIDTH = 60;
const int HEIGHT = 60;

class ActorItem : public QGraphicsItem
{
public:
    ActorItem(int x, int y, int type = 0);
    virtual ~ActorItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setCoord(int x, int y);

private:
    int x_;
    int y_;
    int type_;
    int passenger_num_ = 0;
};

}

#endif // ACTORITEM_HH

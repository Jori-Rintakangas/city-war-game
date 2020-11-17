#include "actoritem.hh"

namespace StudentSide
{
ActorItem::ActorItem(int x, int y, int type):x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_, y_ ));
}

ActorItem::~ActorItem()
{

}

QRectF ActorItem::boundingRect() const
{
    return QRectF(0, 0, WIDTH, HEIGHT);
}

void ActorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (type_ == 1) // Bus stop drawing
    {
        painter->setBrush(Qt::black);
        painter->drawRect(0, 0, 2, 16);
        painter->setBrush(Qt::blue);
        static const QPointF points[3] =
        {
            QPointF(2, 0),
            QPointF(14, 4),
            QPointF(2, 8)
        };
        painter->drawPolygon(points, 3);
    }

    if (type_ == 2) // Bus drawing
    {
        painter->setPen(Qt::black);
        painter->setBrush(Qt::yellow);
        painter->drawRect(0, 0, 16, 8);
        painter->setBrush(Qt::white);
        painter->drawRect(2,1, 5, 5);
        painter->drawRect(9,1, 5, 5);
        painter->setBrush(Qt::black);
        painter->drawEllipse(2, 6, 4, 4);
        painter->drawEllipse(9, 6, 4, 4);
    }
}

void ActorItem::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}

} //namespace

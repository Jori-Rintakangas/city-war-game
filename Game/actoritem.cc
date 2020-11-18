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
        painter->drawRect(0, 0, 30, 15); // bus body
        painter->setBrush(Qt::white);
        painter->drawRect(2, 3, 5, 5); // left window
        painter->drawRect(9, 3, 5, 5); // left window
        painter->setBrush(Qt::black);
        painter->drawEllipse(4, 13, 8, 8); // left wheel
        painter->drawEllipse(17, 13, 8, 8); // right wheel
        painter->setPen(Qt::black);
        QString str_passenger_num = QString::number(passenger_num_);
        painter->drawText(15, 13, str_passenger_num); // display passenger_num_
    }

    if (type_ == 3) // Tower drawing
    {
        painter->setPen(Qt::black);
        painter->setBrush(Qt::white);
        painter->drawRect(0, 0, 10, 30); // tower body

    }

    if (type_ == 4) // Shooting target drawing
    {
        painter->setBrush(Qt::black);
        painter->drawRect(0, 0, 10, 1); // north line
    }
}

void ActorItem::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}

} //namespace

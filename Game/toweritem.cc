#include "toweritem.hh"

namespace StudentSide
{

TowerItem::TowerItem(std::shared_ptr<StudentSide::City> city) :
    city_(city)
{

}

TowerItem::~TowerItem()
{

}

Interface::Location TowerItem::giveLocation() const
{
    return location_;
}

void TowerItem::move(Interface::Location loc)
{
    location_ = loc;
}

bool TowerItem::isRemoved() const
{
    return removed_;
}

void TowerItem::remove()
{
    removed_ = true;
}

Interface::Location TowerItem::createMissile()
{
    location_.setXY(default_x_, default_y_);
    return location_;
}

void TowerItem::updatePosition(ActorItem* missile_item)
{
    missile_item->moveBy(0.01, 0.01);
    location_.setXY(location_.giveX() + 0.01, location_.giveY() - 0.01);
    move(location_);
}

} // namespace

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

Interface::Location TowerItem::createTower()
{
    tower_location_.setXY(default_x_, default_y_);
    return tower_location_;
}

Interface::Location TowerItem::giveLocation() const
{
    return tower_location_;
}

void TowerItem::move(Interface::Location loc)
{
    tower_location_ = loc;
}

bool TowerItem::isRemoved() const
{
    return removed_;
}

void TowerItem::remove()
{
    removed_ = true;
}

} // namespace

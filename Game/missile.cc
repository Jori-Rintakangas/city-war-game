#include "missile.hh"

namespace StudentSide
{

Missile::Missile(std::shared_ptr<StudentSide::City> city) :
    city_(city)
{

}

Missile::~Missile()
{

}

Interface::Location Missile::giveLocation() const
{
    return location_;
}

void Missile::move(Interface::Location loc)
{
    location_ = loc;
}

bool Missile::isRemoved() const
{
    return removed_;
}

void Missile::remove()
{
    removed_ = true;
}

Interface::Location Missile::createMissile()
{
    location_.setXY(default_x_, default_y_);
    return location_;
}

void Missile::updatePosition(ActorItem* missile_item)
{
    missile_item->moveBy(0.01, 0.01);
    location_.setXY(location_.giveX() + 0.01, location_.giveY() - 0.01);
    move(location_);
}

} // namespace

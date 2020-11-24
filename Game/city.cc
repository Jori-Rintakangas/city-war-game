#include "city.hh"
#include <QDebug>

namespace StudentSide
{

City::City()
{

}

City::~City()
{

}

void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    if ( basic_backround_ )
    {
        window_->setPicture(basicbackground);
    }
    else
    {
        window_->setPicture(bigbackground);
    }
}

void City::setClock(QTime clock)
{
    clock_ = clock;
}

void City::addStop(std::shared_ptr<Interface::IStop> stop)
{
    Interface::Location stop_location = stop->getLocation();
    window_->addActor(stop_location.giveX(),stop_location.giveY(), BUS_STOP);
}

void City::startGame()
{

}

void City::addActor(std::shared_ptr<Interface::IActor> new_actor)
{
    ActorItem* actor_item = nullptr;
    Interface::Location actor_location = new_actor->giveLocation();
    if ( std::dynamic_pointer_cast<Interface::IVehicle>(new_actor) != nullptr )
    {
        actor_item = window_->addActor(actor_location.giveX(), actor_location.giveY(), BUS);
        game_actors_.insert({new_actor, actor_item});
    }
    else if ( std::dynamic_pointer_cast<StudentSide::GameCharacter>(new_actor) != nullptr)
    {
        actor_item = window_->addActor(actor_location.giveX(), actor_location.giveY(), CHARACTER);
        actor_location.setXY(actor_location.giveX() + SCALE, actor_location.giveY() - SCALE);
        new_actor->move(actor_location);
        character_item_ = actor_item;
        character_ = new_actor;
    }
    else
    {   // passengers are not drawed to the gamewindow
        game_actors_.insert({new_actor, actor_item});
    }
}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    if ( game_actors_.find(actor) != game_actors_.end() )
    {
        actorRemoved(actor);
        game_actors_.erase(actor);
    }
}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
    ActorItem* actor_item = game_actors_.at(actor);
    window_->deleteActor(actor_item);
}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    if ( game_actors_.find(actor) != game_actors_.end() )
    {
        return true;
    }
    return false;
}

void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    ActorItem* item = game_actors_.at(actor);
    Interface::Location new_location = actor->giveLocation();
    window_->moveActor(item, new_location.giveX(), new_location.giveY());
}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{
    std::vector<std::shared_ptr<Interface::IActor> > nearby_actors = {};
    for ( auto& actor : game_actors_ )
    {
        if ( std::dynamic_pointer_cast<Interface::IVehicle>(actor.first) != nullptr )
        {
            Interface::Location location = actor.first->giveLocation();
            if ( location.isClose(loc,6) )
            {
                nearby_actors.push_back(actor.first);
            }
        }
    }
    return nearby_actors;
}

bool City::isGameOver() const
{
    return false;
}

void City::getGameWindow(std::shared_ptr<StudentSide::GameWindow> window, bool basic)
{
    window_ = window;
    basic_backround_ = basic;
}

void City::executeUserCommand(QKeyEvent *event)
{
    Interface::Location loc = character_->giveLocation();
    if ( event->key() == Qt::Key_D )
    {
        moveHorizontal(STEP);
    }
    if ( event->key() == Qt::Key_A )
    {
        moveHorizontal(-STEP);
    }
    if ( event->key() == Qt::Key_W )
    {
        moveVertical(-STEP);
    }
    if ( event->key() == Qt::Key_S )
    {
        moveVertical(STEP);
    }
    if ( event->key() == Qt::Key_Space )
    {
        std::vector<std::shared_ptr<Interface::IActor>> vec = getNearbyActors(loc);
        if ( vec.size() != 0 )
        {
            for ( auto& bus : vec )
            {
                bus->remove();
            }
        }
    }
}

void City::moveVertical(qreal amount)
{
    Interface::Location loc = character_->giveLocation();
    qreal next_pos = character_item_->y() + amount;
    if ( next_pos < LIMIT_Y && next_pos > 0 )
    {
        character_item_->moveBy(0, amount);
        loc.setXY(loc.giveX(), loc.giveY() - amount);
        character_->move(loc);
    }
}

void City::moveHorizontal(qreal amount)
{
    Interface::Location loc = character_->giveLocation();
    qreal next_pos = character_item_->x() + amount;
    if ( next_pos < LIMIT_X && next_pos > 0 )
    {
        character_item_->moveBy(amount,0);
        loc.setXY(loc.giveX() + amount, loc.giveY());
        character_->move(loc);
    }
}


}

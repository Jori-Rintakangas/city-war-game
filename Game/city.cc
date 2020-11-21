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
    bus_stops_.push_back(stop);
    Interface::Location stop_location = stop->getLocation();
    ActorItem* item = window_->addActor(X_SCALE + stop_location.giveX(), Y_SCALE - stop_location.giveY(), BUS_STOP);
}

void City::startGame()
{

}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    actors_.push_back(newactor);
    ActorItem* actor_item = nullptr;
    Interface::Location actor_location = newactor->giveLocation();
    if ( std::dynamic_pointer_cast<Interface::IVehicle>(newactor) != nullptr )
    {
        actor_item = window_->addActor(X_SCALE + actor_location.giveX(), Y_SCALE - actor_location.giveY(), BUS);
        actor_location.setXY(actor_location.giveX()+BUS_X, actor_location.giveY()-BUS_Y);
        newactor->move(actor_location);
        game_actors_.insert({newactor, actor_item});
    }
    else if ( std::dynamic_pointer_cast<StudentSide::GameCharacter>(newactor) != nullptr)
    {
        actor_item = window_->addActor(X_SCALE + actor_location.giveX(), Y_SCALE - actor_location.giveY(), TARGET);
        actor_location.setXY(actor_location.giveX()+TARGET_SCALE, actor_location.giveY()-TARGET_SCALE);
        newactor->move(actor_location);
    }
    else
    {
        game_actors_.insert({newactor, actor_item});
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
    window_->moveActor(item, X_SCALE + new_location.giveX(), Y_SCALE - new_location.giveY());
}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{
    std::vector<std::shared_ptr<Interface::IActor> > nearby_actors = {};
    for ( auto& actor : game_actors_ )
    {
        if ( std::dynamic_pointer_cast<Interface::IVehicle>(actor.first) != nullptr )
        {
            Interface::Location location = actor.first->giveLocation();
            if ( location.isClose(loc) )
            {
                nearby_actors.push_back(actor.first);
                qDebug() << "is close";
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


}

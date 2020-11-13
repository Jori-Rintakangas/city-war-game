#include "city.hh"

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
    window_->addActor(stop_location.giveX(), 500-stop_location.giveY());
}

void City::startGame()
{

}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    actors_.push_back(newactor);
    Interface::Location actor_location = newactor->giveLocation();
    window_->addActor(actor_location.giveX(), 500-actor_location.giveY());
}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    std::vector<std::shared_ptr<Interface::IActor>>::iterator it;
    it = std::find(actors_.begin(), actors_.end(), actor);
    if ( it != actors_.end() )
    {
        actors_.erase(it);
    }
}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{

}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    if ( std::find(actors_.begin(), actors_.end(), actor) != actors_.end() )
    {
        return true;
    }
    return false;
}

void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{

}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{

}

bool City::isGameOver() const
{
    return false;
}

void City::getGameWindow(std::shared_ptr<CourseSide::SimpleMainWindow> window, bool basic)
{
    window_ = window;
    basic_backround_ = basic;
}


}

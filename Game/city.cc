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
}

void City::startGame()
{

}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    actors_.push_back(newactor);
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

}

void City::getGameWindow(std::shared_ptr<CourseSide::SimpleMainWindow> window, bool basic)
{
    window_ = window;
    basic_backround_ = basic;
}


}

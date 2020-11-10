#include "engine.hh"
#include "creategame.hh"

namespace StudentSide
{

Engine::Engine() :
    window_(new CourseSide::SimpleMainWindow),
    game_logic_(new CourseSide::Logic),
    city_(new StudentSide::City)
{
    //city_ = std::dynamic_pointer_cast<StudentSide::City>(Interface::createGame());
}

void Engine::start()
{
    city_->getGameWindow(window_, true);
    city_->setBackground(basic_, big_);
    window_->show();
}

}

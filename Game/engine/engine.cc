#include "engine.hh"
#include <creategame.hh>

namespace StudentSide
{

Engine::Engine() :
    window_(new CourseSide::SimpleMainWindow),
    game_logic_(new CourseSide::Logic)
{
    city_ = Interface::createGame();
}

void Engine::start()
{
    window_->show();
}

}

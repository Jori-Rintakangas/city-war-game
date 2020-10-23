#include "engine.hh"
#include <creategame.hh>

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

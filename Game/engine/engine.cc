#include "engine.hh"
#include "creategame.hh"

namespace StudentSide
{

Engine::Engine() :
    city_(new StudentSide::City),
    game_character_(new StudentSide::GameCharacter),
    window_(new StudentSide::GameWindow(nullptr, city_)),
    game_logic_(new CourseSide::Logic),
    statistics_(new StudentSide::Statistics(window_))
{
}

void Engine::start()
{
    game_character_->createCharacter();

    city_->getGameWindow(window_, false);
    city_->setBackground(basic_, big_);
    city_->addActor(game_character_);

    window_->show();

    game_logic_->takeCity(city_);
    game_logic_->fileConfig();
    game_logic_->finalizeGameStart();

}

}

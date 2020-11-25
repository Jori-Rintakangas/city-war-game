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

bool Engine::start()
{
    if ( window_->isStarted() )
    {
        game_character_->createCharacter();

        city_->initializeCity(window_, false, statistics_);
        city_->setBackground(basic_, big_);
        city_->addActor(game_character_);
        city_->startGame();

        game_logic_->setTime(16,0);
        game_logic_->takeCity(city_);
        game_logic_->fileConfig();
        game_logic_->finalizeGameStart();

        return true;
    }
    return false;
}

}

#include "engine.hh"
#include "creategame.hh"

namespace StudentSide
{

Engine::Engine() :
    window_(new StudentSide::GameWindow),
    game_logic_(new CourseSide::Logic),
    city_(new StudentSide::City),
    game_character_(new StudentSide::GameCharacter)
{
    //city_ = std::dynamic_pointer_cast<StudentSide::City>(Interface::createGame());
}

void Engine::start()
{
    game_character_->createCharacter();
    city_->getGameWindow(window_, false);
    city_->setBackground(basic_, big_);
    window_->show();
    city_->addActor(game_character_);
    game_logic_->takeCity(city_);
    game_logic_->fileConfig();
    game_logic_->finalizeGameStart();

}

}

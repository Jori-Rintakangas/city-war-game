#include "gamecharacter.hh"

namespace StudentSide
{

GameCharacter::GameCharacter()
{
}

Interface::Location GameCharacter::createCharacter()
{
    character_location_.setXY(default_x_, default_y_);
    return character_location_;
}

Interface::Location GameCharacter::giveLocation() const
{
    return character_location_;
}

void GameCharacter::move(Interface::Location loc)
{

}

bool GameCharacter::isRemoved() const
{

}

void GameCharacter::remove()
{

}

} //namespace

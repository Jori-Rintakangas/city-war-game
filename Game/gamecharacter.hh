#ifndef GAMECHARACTER_HH
#define GAMECHARACTER_HH
#include "interfaces/icity.hh"
#include "gamewindow.hh"
#include "core/location.hh"

namespace StudentSide
{

class GameCharacter : public Interface::IActor
{
public:
    GameCharacter();

    Interface::Location createCharacter();

    Interface::Location giveLocation() const;
    void move(Interface::Location loc);
    bool isRemoved() const;
    void remove();

private:
    Interface::Location character_location_;
    int default_x_ = 200;
    int default_y_ = 200;
};

}
#endif // GAMECHARACTER_HH

/* Code produced by the staff of Tampere University course:
 * TIE-02402 Programming 3: Techniques
 */

#include "gameerror.hh"


namespace Interface
{

GameError::GameError() :
    std::exception(), message_()
{
}


GameError::GameError(const QString& message) :
    std::exception(), message_(message)
{
}


GameError::~GameError()
{
}


const char* GameError::what() const noexcept
{
    return "Interface::GameError";
}


QString GameError::giveMessage() const
{
    return message_;
}

}

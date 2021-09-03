/* Code produced by the staff of Tampere University course:
 * TIE-02402 Programming 3: Techniques
 */

#include "initerror.hh"


namespace Interface
{

InitError::InitError() :
    std::exception(), message_()
{
}


InitError::InitError(const QString& message):
    std::exception(), message_(message)
{
}


InitError::~InitError()
{
}

const char* InitError::what() const noexcept
{
    return "Interface::InitError";
}


QString InitError::giveMessage() const
{
    return message_;
}

}

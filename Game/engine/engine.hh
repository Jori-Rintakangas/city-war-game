#ifndef ENGINE_HH
#define ENGINE_HH
#include <QObject>
#include <memory>
#include "interfaces/icity.hh"
#include "graphics/simplemainwindow.hh"
#include "graphics/simpleactoritem.hh"
#include "core/logic.hh"

namespace StudentSide
{

class Engine : public QObject
{
    Q_OBJECT
public:
    Engine();

    void start();

private:
    std::shared_ptr<Interface::ICity> city_ = nullptr;
    std::shared_ptr<CourseSide::SimpleMainWindow> window_ = nullptr;
    std::shared_ptr<CourseSide::Logic> game_logic_ = nullptr;
};

}
#endif // ENGINE_HH

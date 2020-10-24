#ifndef ENGINE_HH
#define ENGINE_HH
#include <QObject>
#include <memory>
#include "interfaces/icity.hh"
#include "graphics/simplemainwindow.hh"
#include "graphics/simpleactoritem.hh"
#include "core/logic.hh"

const QString BACKROUND = ":/offlinedata/offlinedata/kartta_pieni_500x500.png";

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

    int gaming_time_ = 0;
};

}
#endif // ENGINE_HH

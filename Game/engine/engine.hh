#ifndef ENGINE_HH
#define ENGINE_HH
#include <QObject>
#include <memory>
#include "interfaces/icity.hh"
#include "graphics/simpleactoritem.hh"
//#include "gamewindow.hh"
#include "core/logic.hh"
#include "city.hh"
#include "gamecharacter.hh"
#include "statistics.hh"
#include "toweritem.hh"

const QString BACKROUND_SMALL = ":/offlinedata/offlinedata/kartta_pieni_500x500.png";
const QString BACKROUND_BIG = ":/offlinedata/offlinedata/kartta_iso_1095x592.png";
class GameWindow;
namespace StudentSide
{

class Engine : public QObject
{
    Q_OBJECT
public:
    Engine();

    bool start();

private:

    std::shared_ptr<StudentSide::City> city_ = nullptr;
    std::shared_ptr<StudentSide::GameCharacter> game_character_ = nullptr;
    std::shared_ptr<StudentSide::GameWindow> window_ = nullptr;
    std::shared_ptr<CourseSide::Logic> game_logic_ = nullptr;
    std::shared_ptr<StudentSide::Statistics> statistics_ = nullptr;
    std::shared_ptr<StudentSide::TowerItem> tower_item_ = nullptr;

    int gaming_time_ = 0;
    QImage basic_ = QImage(BACKROUND_SMALL);
    QImage big_ = QImage(BACKROUND_BIG);
};

}
#endif // ENGINE_HH

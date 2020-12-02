#ifndef ENGINE_HH
#define ENGINE_HH

#include <QObject>
#include <memory>

#include "interfaces/icity.hh"
#include "graphics/simpleactoritem.hh"
#include "gamewindow.hh"
#include "core/logic.hh"
#include "city.hh"
#include "gamecharacter.hh"
#include "statistics.hh"
#include "missile.hh"

const QString BACKROUND_SMALL = ":/offlinedata/offlinedata/kartta_pieni_500x500.png";
const QString BACKROUND_BIG = ":/offlinedata/offlinedata/kartta_iso_1095x592.png";

const int DEFAULT_HOUR = 16;
const int DEFAULT_MIN = 0;

namespace StudentSide
{

/*!
 * \brief The Engine class provides necessary resources for the game
 */
class Engine : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Engine constructor
     */
    Engine();

    /*!
     * \brief start calls methods to initialize game
     * \return true if game was started, false otherwise
     */
    bool start();

private:

    std::shared_ptr<City> city_ = nullptr;
    std::shared_ptr<GameCharacter> game_character_ = nullptr;
    std::shared_ptr<GameWindow> window_ = nullptr;
    std::shared_ptr<CourseSide::Logic> game_logic_ = nullptr;
    std::shared_ptr<Statistics> statistics_ = nullptr;
    std::shared_ptr<Missile> tower_item_ = nullptr;

    int gaming_time_ = 0;
    QImage basic_ = QImage(BACKROUND_SMALL);
    QImage big_ = QImage(BACKROUND_BIG);
};

}
#endif // ENGINE_HH

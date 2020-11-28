#ifndef CITY_HH
#define CITY_HH

#include "interfaces/icity.hh"
#include "gamewindow.hh"
#include "gamecharacter.hh"
#include "statistics.hh"
#include "actors/nysse.hh"
#include "toweritem.hh"

#include <QTime>
#include <QKeyEvent>


const int BUS_STOP = 1;
const int BUS = 2;
const int TOWER = 3;
const int CHARACTER = 4;
const int MISSILE = 5;

const int SCALE = 65;
const qreal STEP = 5;

const qreal LIMIT_Y = 373;
const qreal LIMIT_X = 963;

namespace StudentSide
{
/**
 * @brief City class contains operations for handling game characters in the game.
 */
class Statistics;
class GameWindow;
class TowerItem;
class City : public Interface::ICity
{
public:
    /*!
     * \brief City constructor
     */
    City();

    /*! @copydoc Interface::ICity::setBackround(QImage& basicbackground,QImage& bigbackground)
     */
    void setBackground(QImage& basicbackground, QImage& bigbackground);

    /*! @copydoc Interface::ICity::setClock(QTime clock)
     */
    void setClock(QTime clock);

    /*! @copydoc Interface::ICity::addStop(std::shared_ptr<IStop> stop)
     */
    void addStop(std::shared_ptr<Interface::IStop> stop);

    /*! @copydoc Interface::ICity::startGame()
     */
    void startGame();

    /*! @copydoc Interface::ICity::addActor(std::shared_ptr<IActor> newactor)
     */
    void addActor(std::shared_ptr<Interface::IActor> newactor);

    /*! @copydoc Interface::ICity::removeActor(std::shared_ptr<IActor> actor)
     */
    void removeActor(std::shared_ptr<Interface::IActor> actor);

    /*! @copydoc Interface::ICity::actorRemoved(std::shared_ptr<IActor> actor)
     */
    void actorRemoved(std::shared_ptr<Interface::IActor> actor);

    /*! @copydoc Interface::ICity::findActor(std::shared_ptr<IActor> actor) const
     */
    bool findActor(std::shared_ptr<Interface::IActor> actor) const;

    /*! @copydoc Interface::ICity::actorMoved(std::shared_ptr<IActor> actor)
     */
    void actorMoved(std::shared_ptr<Interface::IActor> actor);

    /*! @copydoc Interface::ICity::getNearbyActors(Location loc) const
     */
    std::vector<std::shared_ptr<Interface::IActor>> getNearbyActors(Interface::Location loc) const;

    /*! @copydoc Interface::ICity::isGameOver() const
     */
    bool isGameOver() const;

    /*!
     * \brief initializeCity gets the initialization information for the city.
     * \param window A pointer to a gamewindow used in the game
     * \param basic Game's background type
     * \param statistics A pointer to city's statistics class
     */
    void initializeCity(std::shared_ptr<StudentSide::GameWindow> window, bool basic, std::shared_ptr<StudentSide::Statistics> statistics);

    /*!
     * \brief executeUserCommand executes the command that user wants
     * \param event A pointer that contains information of pressed key on the keyboard.
     */
    void executeUserCommand(QKeyEvent* event);

    /*!
     * \brief moveVertical moves game character in vertical direction in the gamewindow
     * \param amount The amount of movement
     */
    void moveVertical(qreal amount);

    /*!
     * \brief moveHorizontal moves game character in horizontal direction in the gamewindow
     * \param amount The amount of movement
     */
    void moveHorizontal(qreal amount);

    /*!
     * \brief City destructor
     */
    virtual ~City();

private:

    QTime clock_;
    std::shared_ptr<StudentSide::GameWindow> window_ = nullptr;
    bool basic_backround_ = true;

    std::map<std::shared_ptr<Interface::IActor>, ActorItem*> game_actors_;
    ActorItem* missile_item_ = nullptr;
    ActorItem* character_item_ = nullptr;
    std::shared_ptr<Interface::IActor> character_ = nullptr;
    std::shared_ptr<StudentSide::Statistics> statistics_ = nullptr;
    std::shared_ptr<StudentSide::TowerItem> missile_ = nullptr;
};

}
#endif // CITY_HH

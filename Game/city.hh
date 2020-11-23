#ifndef CITY_HH
#define CITY_HH
#include "interfaces/icity.hh"
#include "gamewindow.hh"
#include "gamecharacter.hh"

#include <QTime>
#include <QKeyEvent>


const int BUS_STOP = 1;
const int BUS = 2;
const int TOWER = 3;
const int CHARACTER = 4;

const int SCALE = 65;
const qreal STEP = 5;

namespace StudentSide
{
/**
 * @brief City class contains operations for handling game characters in the game.
 */

class GameWindow;
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
     * \brief getGameWindow gets the window for the game and game's background type
     * \param window A pointer to a gamewindow used in the game
     * \param basic Game's background type
     */
    void getGameWindow(std::shared_ptr<StudentSide::GameWindow> window, bool basic);

    /*!
     * \brief executeUserCommand executes the command that user wants
     * \param event A pointer that contains information of pressed key on the keyboard.
     */
    void executeUserCommand(QKeyEvent* event);

    /*!
     * \brief City destructor
     */
    virtual ~City();

private:

    QTime clock_;
    std::shared_ptr<StudentSide::GameWindow> window_ = nullptr;
    bool basic_backround_ = true;

    std::map<std::shared_ptr<Interface::IActor>, ActorItem*> game_actors_;

    ActorItem* character_item_;
    std::shared_ptr<Interface::IActor> character_;
};

}
#endif // CITY_HH

#ifndef CITY_HH
#define CITY_HH
#include "interfaces/icity.hh"
#include "gamewindow.hh"
#include <QTime>


const int BUS_STOP = 1;
const int BUS = 2;
const int CHARACTER = 3;

namespace StudentSide
{

class City : public Interface::ICity
{
public:
    City();

    void setBackground(QImage& basicbackground, QImage& bigbackground);
    void setClock(QTime clock);
    void addStop(std::shared_ptr<Interface::IStop> stop);
    void startGame();
    void addActor(std::shared_ptr<Interface::IActor> newactor);
    void removeActor(std::shared_ptr<Interface::IActor> actor);
    void actorRemoved(std::shared_ptr<Interface::IActor> actor);
    bool findActor(std::shared_ptr<Interface::IActor> actor) const;
    void actorMoved(std::shared_ptr<Interface::IActor> actor);
    std::vector<std::shared_ptr<Interface::IActor>> getNearbyActors(Interface::Location loc) const;
    bool isGameOver() const;

    void getGameWindow(std::shared_ptr<StudentSide::GameWindow> window, bool basic);

    virtual ~City();

private:

    QTime clock_;
    std::shared_ptr<StudentSide::GameWindow> window_ = nullptr;
    bool basic_backround_ = true;

    std::vector<std::shared_ptr<Interface::IStop>> bus_stops_;
    std::vector<std::shared_ptr<Interface::IActor>> actors_;
    std::map<std::shared_ptr<Interface::IActor>, ActorItem*> game_actors_;
};

}
#endif // CITY_HH

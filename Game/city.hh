#ifndef CITY_HH
#define CITY_HH
#include "interfaces/icity.hh"
#include <QTime>

namespace Studentside
{

class City : public Interface::ICity
{
public:
    City();

    void setBackground(QImage& basicbackground, QImage& bigbackground) = 0;
    void setClock(QTime clock) = 0;
    void addStop(std::shared_ptr<Interface::IStop> stop) = 0;
    void startGame() = 0;
    void addActor(std::shared_ptr<Interface::IActor> newactor) = 0;
    void removeActor(std::shared_ptr<Interface::IActor> actor) = 0;
    void actorRemoved(std::shared_ptr<Interface::IActor> actor) = 0;
    bool findActor(std::shared_ptr<Interface::IActor> actor) const = 0;
    void actorMoved(std::shared_ptr<Interface::IActor> actor) = 0;
    std::vector<std::shared_ptr<Interface::IActor>> getNearbyActors(Interface::Location loc) const = 0;
    bool isGameOver() const = 0;


private:
    QTime clock_;
};

}
#endif // CITY_HH

#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "gamewindow.hh"

namespace StudentSide
{

class Statistics
{
public:
    Statistics(std::shared_ptr<StudentSide::GameWindow> window);
    void scoreUpdate();
    void accuracyUpdate();
    void shotFired();
    void shotHit();
    void busDestroyed();
    void enemyDestroyed(int enemy_num);

private:
    std::shared_ptr<StudentSide::GameWindow> window_ = nullptr;

    int score_ = 0;
    int accuracy_ = 0; //%
    int destroyed_buses_ = 0;
    int destroyed_enemies_ = 0;
    int total_shots_ = 0;
    int hit_shots_ = 0;

};

} //namespace
#endif // STATISTICS_HH

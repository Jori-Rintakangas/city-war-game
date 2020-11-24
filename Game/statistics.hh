#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "gamewindow.hh"

namespace StudentSide
{

class Statistics
{
public:
    Statistics(std::shared_ptr<StudentSide::GameWindow> window);
    void scoreCalculate();
    void accuracyCalculate();
    void scoreShow();
    void accuracyShow();
    void busDestroyed();
    void enemyDestroyed();
    void shotFired();
    void shotHit();

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

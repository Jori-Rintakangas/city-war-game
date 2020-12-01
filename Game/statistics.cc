#include "statistics.hh"
#include <cmath>
#include <QDebug>

namespace StudentSide
{

Statistics::Statistics(std::shared_ptr<GameWindow> window) :
    window_(window)
{
}

void Statistics::scoreUpdate()
{
    score_ = destroyed_buses_ * 3 + destroyed_enemies_;
    window_->updateScore(score_);
}

void Statistics::accuracyUpdate()
{
    accuracy_ = (int) round(hit_shots_ / total_shots_ * 100);
    window_->updateAccuracy(accuracy_);
}

void Statistics::shotFired()
{
    total_shots_++;
}

void Statistics::shotHit()
{
    hit_shots_++;
}

void Statistics::busDestroyed()
{
    destroyed_buses_++;
}

void Statistics::enemyDestroyed(int enemy_num)
{
    destroyed_enemies_ += enemy_num;
}

} //namespace

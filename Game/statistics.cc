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

int Statistics::getTotalShots() const
{
    return total_shots_;
}

int Statistics::getHitShots() const
{
    return hit_shots_;
}

int Statistics::getDestroyedBuses() const
{
    return destroyed_buses_;
}

int Statistics::getDestroyedEnemies() const
{
    return destroyed_enemies_;
}

int Statistics::getScore() const
{
    return score_;
}

int Statistics::getAccuracy() const
{
    return accuracy_;
}

} //namespace

#include "statistics.hh"

namespace StudentSide
{

Statistics::Statistics(std::shared_ptr<StudentSide::GameWindow> window) :
    window_(window)
{
}

void Statistics::scoreCalculate()
{
    score_ = destroyed_buses_ * 3 + destroyed_enemies_;
}

void Statistics::accuracyCalculate()
{
    accuracy_ = (int) round(hit_shots_ / total_shots_);
}

void Statistics::scoreShow()
{
    window_->updateScore(score_);
}

void Statistics::accuracyShow()
{
    window_->updateAccuracy(accuracy_);
}

void Statistics::busDestroyed()
{
}

void Statistics::enemyDestroyed()
{
}

void Statistics::shotFired()
{
}

void Statistics::shotHit()
{
}

} //namespace

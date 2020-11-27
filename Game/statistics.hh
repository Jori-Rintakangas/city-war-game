#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "gamewindow.hh"

namespace StudentSide
{
/**
 * @brief Statistics class contains operations for handling statistics data.
 */
class GameWindow;
class Statistics
{
public:
    /**
     * @brief constructor of Statistics
     * @param window is pointer of the game window.
     */
    Statistics(std::shared_ptr<StudentSide::GameWindow> window);

    /**
     * @brief new score is calculated and updated at game window.
     */
    void scoreUpdate();

    /**
     * @brief new accuracy is calculated and updated at game window.
     */
    void accuracyUpdate();

    /**
     * @brief count how many shot is fired.
     */
    void shotFired();

    /**
     * @brief count how many shot is hit the bus.
     */
    void shotHit();

    /**
     * @brief count how many buses are destroyed.
     */
    void busDestroyed();

    /**
     * @brief count how many enemies are destroyed.
     * @param enemy_num killed by the lastest shot.
     */
    void enemyDestroyed(int enemy_num);

private:
    std::shared_ptr<StudentSide::GameWindow> window_ = nullptr;

    int score_ = 0;
    int accuracy_ = 0; //%
    int destroyed_buses_ = 0;
    int destroyed_enemies_ = 0;
    double total_shots_ = 0;
    double hit_shots_ = 0;

};

} //namespace
#endif // STATISTICS_HH

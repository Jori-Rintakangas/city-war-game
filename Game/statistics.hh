#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "gamewindow.hh"

namespace StudentSide
{

class GameWindow;
/**
 * @brief Statistics class contains operations for handling statistics data.
 */
class Statistics
{
public:
    /**
     * @brief constructor of Statistics
     * @param window is pointer of the game window.
     */
    Statistics(std::shared_ptr<GameWindow> window);

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

    /*!
     * \brief getTotalShots returns the total amount of shots happened during the game
     * \return amount of total shots
     */
    int getTotalShots() const;

    /*!
     * \brief getHitShots returns the amount of shots that hit the enemy during the game
     * \return amount of shots that hit the enemy
     */
    int getHitShots() const;

    /*!
     * \brief getDestroyedBuses returns the amount of destroyed buses during the game
     * \return The amount of destroyed buses
     */
    int getDestroyedBuses() const;

    /*!
     * \brief getDestroyedEnemies returns the amount of destroyed enemies during the game
     * \return The amount of destroyed enemies
     */
    int getDestroyedEnemies() const;

    /*!
     * \brief getScore returns the score obtained during the game
     * \return The score of the game
     */
    int getScore() const;

    /*!
     * \brief getAccuracy returns the shooting accuracy obtained during the game
     * \return The shooting accuracy of the game
     */
    int getAccuracy() const;

private:
    std::shared_ptr<GameWindow> window_ = nullptr;

    int score_ = 0;
    int accuracy_ = 0; //%
    int destroyed_buses_ = 0;
    int destroyed_enemies_ = 0;
    double total_shots_ = 0;
    double hit_shots_ = 0;

};

} //namespace
#endif // STATISTICS_HH

#ifndef TOWERITEM_HH
#define TOWERITEM_HH

#include "interfaces/icity.hh"
#include "gamewindow.hh"
#include "core/location.hh"

namespace StudentSide
{

/**
 * @brief TowerItem class contains operations for handling tower item (missile) in the game.
 */
class City;
class TowerItem : public Interface::IActor
{
public:
    /**
     * @brief constructor of TowerItem
     */
    TowerItem(std::shared_ptr<StudentSide::City> city);

    /**
     * \brief TowerItem destructor
     */
    virtual ~TowerItem();

    /**
     * \brief giveLocation returns the tower's location
     * \return Location object of the tower
     */
    Interface::Location giveLocation() const;

    /**
     * \brief move tower to new location
     * \param loc tower's new location
     */
    void move(Interface::Location loc);

    /*!
     * \brief isRemoved tells if the tower is removed from the game
     * \return true if removed, false if not
     */
    bool isRemoved() const;

    /*!
     * \brief remove the tower as removed
     */
    void remove();

    /**
     * \brief createTowerItem creates tower with default location
     * \return Location object of the tower
     */
    Interface::Location createMissile();

    /**
     * @brief updatePosition
     * @param missile_item
     */
    void updatePosition(ActorItem* missile_item);

private:
    Interface::Location location_;
    std::shared_ptr<StudentSide::City> city_ = nullptr;

    int default_x_ = -110;
    int default_y_ = 550;

    bool removed_ = false;
};

} //namespace
#endif // TOWERITEM_HH

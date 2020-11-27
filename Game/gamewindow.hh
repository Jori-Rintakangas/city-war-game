#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH

#include "interfaces/iactor.hh"
#include "actoritem.hh"
#include "gamecharacter.hh"
#include "city.hh"
#include "startdialog.hh"
#include "ui_startdialog.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <map>
#include <QPushButton>
#include <QString>


namespace Ui
{


class GameWindow;
}

namespace StudentSide
{

const int X_SCALE = 349;
const int Y_SCALE = 553;

/**
 * @brief defines operations of the game window
 */
class City;
class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief game window constructor
     * @param parent is pointing the parent class.
     * @param game_city is pointer of city class for building the game environment.
     */
    explicit GameWindow(QWidget *parent = nullptr, std::shared_ptr<StudentSide::City> game_city = nullptr);

    /**
     * @brief virtual destructor of game window
     */
    virtual ~GameWindow();

    /**
     * @brief add actor on the map.
     * @param locX where the actor will be drawn on x axis
     * @param locY where the actor will be drawn on y axis
     * @param type of the actor
     * @return
     */
    ActorItem* addActor(int locX, int locY, int type = 0);

    /**
     * @brief move item to another location on the map
     * @param item which will be moved.
     * @param locX where the item will be moved on x axis
     * @param locY where the item will be moved on y axis
     * @param type of movement
     */
    void moveActor(ActorItem* item, int locX, int locY, int type = 0);

    /**
     * @brief delete item from the map
     * @param item which will be removed.
     */
    void deleteActor(ActorItem* item);

    /**
     * @brief set picture of the map.
     * @param img is the background picture
     */
    void setPicture(QImage &img);

    /**
     * @brief read input time given by user
     * @param input_min what user chose.
     */
    void readInputTime(int input_min);

    /**
     * @brief implementation when game is over
     */
    void gameOver();

    /**
     * @brief update score number on the line edit
     * @param score is new score for updating
     */
    void updateScore(int score = 0);

    /**
     * @brief update accuracy number on line edit
     * @param accuracy is new accuracy for updating
     */
    void updateAccuracy(int accuracy = 0);

    /**
     * @brief checking the key press event
     * @param event of key pressing
     */
    void keyPressEvent(QKeyEvent* event) override;

    /**
     * @brief checking the game is started by user
     * @return the game is started or not
     */
    bool isStarted();

private slots:
    /**
     * @brief display the how much time left for game at lcd number
     */
    void displayLeftTime();

private:
    Ui::GameWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    std::shared_ptr<StudentSide::City> game_city_;
    StartDialog* dialog_;

    int width_ = 1095; //pxls
    int height_ = 592;
    int total_time_ = 0; //s
    int spent_time_ = 0; //s
    int left_min_ = 0;
    int left_sec_ = 0;
    int score_ = 0;
    int accuracy_ = 0;

    bool is_running_ = false;
    bool is_game_over_ = true;

};

} //namespace
#endif // GAMEWINDOW_HH


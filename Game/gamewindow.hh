#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH

#include "interfaces/iactor.hh"
#include "actoritem.hh"
#include "gamecharacter.hh"
#include "city.hh"

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

class City;

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr, std::shared_ptr<StudentSide::City> game_city = nullptr);
    virtual ~GameWindow();

    ActorItem* addActor(int locX, int locY, int type = 0);
    void moveActor(ActorItem* item, int locX, int locY, int type = 0);
    void deleteActor(ActorItem* item);
    void setPicture(QImage &img);
    void readInputTime(int input_min);
    void gameOver();
    void updateScore(int score = 0);
    void keyPressEvent(QKeyEvent* event) override;

signals:
    //void gameStarted();

private slots:
    void displayLeftTime();

private:
    Ui::GameWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    std::shared_ptr<StudentSide::City> game_city_;

    int width_ = 1095; //pxls
    int height_ = 592;
    int total_time_ = 0; //s
    int spent_time_ = 0; //s
    int left_min_ = 0;
    int left_sec_ = 0;
    int score_ = 0;

    bool is_running_ = false;
    bool is_game_over_ = true;

};

} //namespace
#endif // GAMEWINDOW_HH


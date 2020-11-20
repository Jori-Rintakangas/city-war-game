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

const qreal STEP = 5;

namespace Ui
{
class GameWindow;
}

namespace StudentSide
{
class City;
class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr, std::shared_ptr<Interface::IActor> character = nullptr,
                        std::shared_ptr<StudentSide::City> game_city = nullptr);
    virtual ~GameWindow();

    void setSize(int w, int h);
    void setTick(int t);

    virtual ActorItem* addActor(int locX, int locY, int type = 0);
    void moveActor(ActorItem* item, int locX, int locY, int type = 0);
    void deleteActor(ActorItem* item);
    void setPicture(QImage &img);
    void startOrStop();
    void readInputTime(int input_min);
    void gameOver();
    void updateScore(int score = 0);
    void keyPressEvent(QKeyEvent* event) override;

signals:
    void gameStarted();

private slots:
    void on_startButton_clicked();
    void displayLeftTime();

private:
    Ui::GameWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    QVector<QGraphicsItem*> actors_;
    ActorItem* target_;
    std::shared_ptr<Interface::IActor> character_;
    std::shared_ptr<StudentSide::City> game_city_;

    int width_ = 1095; //pxls
    int height_ = 592;
    int tick_ = 500; //ms
    int total_time_ = 0; //s
    int spent_time_ = 0; //s
    int left_min_ = 0;
    int left_sec_ = 0;

    bool is_running_ = false;
    bool is_game_over_ = true;

    static const QString S_START;
    static const QString S_STOP;
};

} //namespace
#endif // GAMEWINDOW_HH


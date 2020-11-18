#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH

#include "interfaces/iactor.hh"
#include "actoritem.hh"

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

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    virtual ~GameWindow();

    void setSize(int w, int h);
    void setTick(int t);

    virtual ActorItem* addActor(int locX, int locY, int type = 0);
    void updateCoords(int nX, int nY);
    void setPicture(QImage &img);
    void startOrStop();
    void moveActor(ActorItem* item, int locX, int locY, int type = 0);
    void deleteActor(ActorItem* item);
    void displayLeftTime(int input_min);
    void updateScore(int score = 0);

signals:
    void gameStarted();

private slots:
    void on_startButton_clicked();

private:
    Ui::GameWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    QVector<QGraphicsItem*> actors_;
    ActorItem* last_;

    int width_ = 1095; //pxls
    int height_ = 592;
    int tick_ = 500; //ms
    int left_min_ = 0;
    int left_sec_ = 0;

    bool is_running_ = false;
    bool is_game_over_ = true;

    static const QString S_START;
    static const QString S_STOP;
};

} //namespace
#endif // GAMEWINDOW_HH


#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH

#include "interfaces/iactor.hh"
#include "graphics/simpleactoritem.hh"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <map>

namespace Ui {
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

    virtual void addActor(int locX, int locY, int type = 0);
    void updateCoords(int nX, int nY);
    void setPicture(QImage &img);

signals:
    void gameStarted();

private slots:
    void on_startButton_clicked();

private:
    Ui::GameWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    QVector<QGraphicsItem*> actors_;
    CourseSide::SimpleActorItem* last_;

    int width_ = 1095; //pxls
    int height_ = 592;
    int tick_ = 500; //ms
};

} //namespace
#endif // GAMEWINDOW_HH


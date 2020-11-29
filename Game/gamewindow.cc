#include "gamewindow.hh"
#include "ui_gamewindow.h"
#include "startdialog.hh"
#include "ui_startdialog.h"

#include <QDebug>
#include <QMessageBox>
#include <QTime>
#include <QKeyEvent>

const int PADDING = 10;
const int SIZE_SCALE = 3;

namespace StudentSide
{

GameWindow::GameWindow(QWidget *parent, std::shared_ptr<City> game_city) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    game_city_(game_city)
{
    ui->setupUi(this);
    ui->gameView->setFixedSize(width_+SIZE_SCALE, height_+SIZE_SCALE);
    ui->centralwidget->setFixedSize(width_ + 4 * PADDING, height_ + PADDING);

    map = new QGraphicsScene(this);
    ui->gameView->setScene(map);
    map->setSceneRect(0,0,width_,height_);

    resize(minimumSizeHint());
    //ui->gameView->fitInView(0,0, MAPWIDTH, MAPHEIGHT, Qt::KeepAspectRatio);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displayLeftTime()));

    dialog_ = new StartDialog;
    connect(dialog_, &StartDialog::signal_send, this, &GameWindow::readInputTime);
    dialog_->exec();
    timer->start(1000);

    ui->score->setText(QString::number(0));
    ui->score->setReadOnly(true);
    ui->accuracy->setText(QString::number(0));
    ui->accuracy->setReadOnly(true);
}

GameWindow::~GameWindow()
{
    delete ui;
}

ActorItem* GameWindow::addActor(int locX, int locY, int type)
{
    ActorItem* nActor = new ActorItem(X_SCALE + locX, Y_SCALE - locY, type);
    if ( type == 4 ) // if target character
    {
        nActor->setZValue(1); // used to keep target on top of other items
    }
    map->addItem(nActor);
    return nActor;
}

void GameWindow::moveActor(ActorItem* item, int locX, int locY, int type)
{
    if ( item != nullptr)
    {
        item->setCoord( X_SCALE + locX, Y_SCALE - locY);
    }
}

void GameWindow::deleteActor(ActorItem* item)
{
    if ( item != nullptr )
    {
        map->removeItem(item);
        delete item;
    }
}

void GameWindow::setPicture(QImage &img)
{
    map->setBackgroundBrush(img);
}

void GameWindow::readInputTime(int input_min)
{
    ui->left_m->display(input_min);
    total_time_ = input_min * 60; //s
}

void GameWindow::displayLeftTime()
{
    ++spent_time_;
    int left_time = total_time_ - spent_time_;
    left_min_ =  left_time / 60;
    left_sec_ =  left_time % 60;
    ui->left_m->display(left_min_);
    ui->left_s->display(left_sec_);

    if (left_min_ == 0 and left_sec_ == 0)
    {
        gameOver(false);
    }
}

void GameWindow::gameOver(bool killed)
{
    timer->stop();
    is_game_over_ = true;
    is_running_ = false;
    QMessageBox msgBox;
    QString status = QString("GAME OVER :) Times up! \n Your score is %1. \n Your accuracy is %2%. ").arg(score_).arg(accuracy_);
    QMessageBox::information(this, tr("Info"), status);
    this->close();
}

void GameWindow::updateScore(int score)
{
    score_ = score;
    ui->score->setText(QString::number(score_));
}

void GameWindow::updateAccuracy(int accuracy)
{
    accuracy_ = accuracy;
    ui->accuracy->setText(QString::number((accuracy)));
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    game_city_->executeUserCommand(event);
}

bool GameWindow::isStarted()
{
    if ( dialog_->result() == 0 )
    {
        return false;
    }
    return true;
}

} //namespace


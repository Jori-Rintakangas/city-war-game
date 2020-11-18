#include "gamewindow.hh"
#include "ui_gamewindow.h"
#include "startdialog.hh"
#include "ui_startdialog.h"

#include <QDebug>
#include<QMessageBox>

const int PADDING = 10;
const QString StudentSide::GameWindow::S_START = QString("Start");
const QString StudentSide::GameWindow::S_STOP = QString("Stop");

namespace StudentSide
{

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->gameView->setFixedSize(width_, height_);
    ui->centralwidget->setFixedSize(width_ + ui->startButton->width() + PADDING, height_ + PADDING);

    ui->startButton->move(width_ + PADDING , PADDING);
    connect(ui->startButton, &QPushButton::clicked,
                this, &GameWindow::startOrStop);


    map = new QGraphicsScene(this);
    ui->gameView->setScene(map);
    map->setSceneRect(0,0,width_,height_);

    resize(minimumSizeHint());
    //ui->gameView->fitInView(0,0, MAPWIDTH, MAPHEIGHT, Qt::KeepAspectRatio);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    timer->start(tick_);

    StartDialog* dialog = new StartDialog;
    connect(dialog, &StartDialog::signal_send, this, &GameWindow::displayLeftTime);
    dialog->exec();

}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::setSize(int w, int h)
{
    width_ = w;
    height_ = h;
}

void GameWindow::setTick(int t)
{
    tick_ = t;
}

ActorItem* GameWindow::addActor(int locX, int locY, int type)
{
    ActorItem* nActor = new ActorItem(locX, locY, type);
    actors_.push_back(nActor);
    map->addItem(nActor);
    last_ = nActor;
    return nActor;
}

void GameWindow::updateCoords(int nX, int nY)
{
    last_->setCoord(nX, nY);
}

void GameWindow::setPicture(QImage &img)
{
    map->setBackgroundBrush(img);
}

void GameWindow::startOrStop()
{
    if(ui->startButton->text() == GameWindow::S_START)
    {
        is_running_ = true;
        timer->start();
        ui->startButton->setText(GameWindow::S_STOP);
    }
    else
    {
        is_running_ = false;
        timer->stop();
        ui->startButton->setText(GameWindow::S_START);
    }
}

void GameWindow::moveActor(ActorItem* item, int locX, int locY, int type)
{
    if ( item != nullptr)
    {
        item->setCoord(locX, locY);
    }
}

void GameWindow::deleteActor(ActorItem* item)
{
    map->removeItem(item);
}

void GameWindow::displayLeftTime(int input_min)
{
    left_min_ = input_min;
    ui->left_m->display(left_min_);
    ui->left_s->display(left_sec_);

    if (left_min_ == 0 and left_sec_ == 0)
    {
        is_game_over_ = true;
        QMessageBox::information(this, tr("ERROR"), tr("GAME OVER. Times up! \n See you next time."));
    }
}

void GameWindow::updateScore(int score)
{
    ui->score_lcd->display(score);
}

} //namespace

void StudentSide::GameWindow::on_startButton_clicked()
{
    qDebug() << "Start clicked";
    emit gameStarted();

}

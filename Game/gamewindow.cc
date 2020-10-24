#include "gamewindow.hh"
#include "ui_gamewindow.h"

namespace StudentSide
{

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
}

GameWindow::~GameWindow()
{
    delete ui;
}

}

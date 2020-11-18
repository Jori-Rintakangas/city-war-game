#include "startdialog.hh"
#include "ui_startdialog.h"

#include <QMessageBox>

namespace StudentSide
{

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::on_game_time_valueChanged(int input_min)
{
    game_time_ = input_min;
}

void StartDialog::accept()
{
    if (game_time_ != 0)
    {
        emit signal_send(game_time_);
        QDialog::accept();
    }
    else
    {
        QMessageBox::information(this, tr("ERROR"), tr("Invalid number of game time.\n Pick number more than 0."));
    }
}

}



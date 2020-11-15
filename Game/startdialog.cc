#include "startdialog.hh"
#include "ui_startdialog.h"

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
    game_time = input_min;
}

void StartDialog::accept()
{
    QDialog::accept();
}

}



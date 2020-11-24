#ifndef STARTDIALOG_HH
#define STARTDIALOG_HH

#include <QDialog>

namespace Ui
{
class StartDialog;
}

namespace StudentSide
{

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = nullptr);
    ~StartDialog();

signals:
    void signal_send(int);

private slots:

    void on_game_time_valueChanged(int arg1);

    void accept() override;

private:
    Ui::StartDialog *ui;
    int game_time_ = 1;
};

} //namespace
#endif // STARTDIALOG_HH

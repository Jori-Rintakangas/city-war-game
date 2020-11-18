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

    void accept() override;

    void on_game_time_valueChanged(int arg1);

private:
    Ui::StartDialog *ui;
    int game_time_;
};

} //namespace
#endif // STARTDIALOG_HH

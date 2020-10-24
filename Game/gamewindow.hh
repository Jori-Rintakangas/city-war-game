#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH

#include <QMainWindow>

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
    ~GameWindow();

private:
    Ui::GameWindow *ui;
};

}
#endif // GAMEWINDOW_HH

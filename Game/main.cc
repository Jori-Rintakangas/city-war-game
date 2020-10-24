#include <QApplication>
#include "engine/engine.hh"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    StudentSide::Engine e;
    e.start();
    return a.exec();
}



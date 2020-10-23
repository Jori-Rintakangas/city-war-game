#include <QApplication>
#include "engine/engine.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    Engine e;
    e.start();
    return a.exec();
}

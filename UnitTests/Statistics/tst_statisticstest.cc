#include "statistics.hh"
#include "gamewindow.hh"
#include "actoritem.hh"
#include "city.hh"
#include "engine/engine.hh"
#include <QtTest>
#include <QString>
#include <QKeyEvent>

// add necessary includes here

class Statisticstest : public QObject
{
    Q_OBJECT

public:
    Statisticstest();
    ~Statisticstest();

private slots:
    void test_case1();

};

Statisticstest::Statisticstest()
{

}

Statisticstest::~Statisticstest()
{

}

void Statisticstest::test_case1()
{

}

QTEST_MAIN(Statisticstest)

#include "tst_statisticstest.moc"

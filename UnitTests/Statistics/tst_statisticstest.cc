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
    void testInitializationValues();
    void testIncrements();
    void testUpdates();

};

Statisticstest::Statisticstest()
{

}

Statisticstest::~Statisticstest()
{

}

void Statisticstest::testInitializationValues()
{
    StudentSide::Statistics statistics;
    QVERIFY2(statistics.busDestroyed() == 0, "Error, wrong initalization value");
    QVERIFY2(statistics.enemyDestroyed(0) == 0, "Error, wrong initalization value");
    QVERIFY2(statistics.shotHit() == 0, "Error, wrong initalization value");
    QVERIFY2(statistics.shotFired() == 0, "Error, wrong initalization value");
}

void Statisticstest::testIncrements()
{
    StudentSide::Statistics statistics;
    statistics.busDestroyed();
    QVERIFY2(statistics.busDestroyed() == 1, "Error, invalid increment in Destroyed Buses");

    statistics.enemyDestroyed(1);
    QVERIFY2(statistics.enemyDestroyed(1) == 1, "Error, invalid increment in Destroyed Enemies");

    statistics.shotHit();
    QVERIFY2(statistics.shotHit() == 1, "Error, invalid increment in Hit Shots");

    statistics.shotFired();
    QVERIFY2(statistics.shotFired() == 1, "Error, invalid increment in Fired Shots");
}

void Statisticstest::testUpdates()
{
    std::shared_ptr<StudentSide::City> city(new StudentSide::City);
    std::shared_ptr<StudentSide::GameWindow> window(new StudentSide::GameWindow(nullptr, city));
    StudentSide::Statistics statistics;

    statistics.busDestroyed();
    statistics.enemyDestroyed(1);
    statistics.shotHit();
    statistics.shotFired();

    statistics.score();
    statistics.accuracy();

    QVERIFY2(statistics.score() == 4, "Error, invalid score value");
    QVERIFY2(statistics.accuracy() == 100, "Error, invalid accuracy value");
}

QTEST_MAIN(Statisticstest)

#include "tst_statisticstest.moc"



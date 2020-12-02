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
    StudentSide::Statistics statistics(nullptr);
    QVERIFY2(statistics.getDestroyedBuses() == 0, "Error, wrong initalization value");
    QVERIFY2(statistics.getDestroyedEnemies() == 0, "Error, wrong initalization value");
    QVERIFY2(statistics.getHitShots() == 0, "Error, wrong initalization value");
    QVERIFY2(statistics.getTotalShots() == 0, "Error, wrong initalization value");
}

void Statisticstest::testIncrements()
{
    StudentSide::Statistics statistics(nullptr);
    statistics.busDestroyed();
    QVERIFY2(statistics.getDestroyedBuses() == 1, "Error, invalid increment in Destroyed Buses");

    statistics.enemyDestroyed(1);
    QVERIFY2(statistics.getDestroyedEnemies() == 1, "Error, invalid increment in Destroyed Enemies");

    statistics.shotHit();
    QVERIFY2(statistics.getHitShots() == 1, "Error, invalid increment in Hit Shots");

    statistics.shotFired();
    QVERIFY2(statistics.getTotalShots() == 1, "Error, invalid increment in Fired Shots");
}

void Statisticstest::testUpdates()
{
    std::shared_ptr<StudentSide::City> city(new StudentSide::City);
    std::shared_ptr<StudentSide::GameWindow> window(new StudentSide::GameWindow(nullptr, city));
    StudentSide::Statistics statistics(window);

    statistics.busDestroyed();
    statistics.enemyDestroyed(1);
    statistics.shotHit();
    statistics.shotFired();

    statistics.scoreUpdate();
    statistics.accuracyUpdate();

    QVERIFY2(statistics.getScore() == 4, "Error, invalid score value");
    QVERIFY2(statistics.getAccuracy() == 100, "Error, invalid accuracy value");
}


QTEST_MAIN(Statisticstest)

#include "tst_statisticstest.moc"



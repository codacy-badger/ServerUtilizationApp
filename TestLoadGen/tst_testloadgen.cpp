#include <QtTest>
#include <QMap>
#include <QDebug>
#include <QTextStream>
#include "MMProcess.h"

class TestLoadGen : public QObject
{
    Q_OBJECT

public:
    TestLoadGen();

    MMProcess TestProcess;
    int WaitCnt{0};

private slots:
    void HistogramOfArrivaltime();
    void HistogramOfServicetime();
    void TestTimer();
};

TestLoadGen::TestLoadGen()
  : TestProcess(nullptr, msec_t(10), msec_t(1))
{
    qDebug() << fixed << qSetRealNumberPrecision(2);
}

void TestLoadGen::HistogramOfServicetime()
{
    QMap<int, int> hist;
    for (int n = 0; n < 10000; ++n)
    {
        ++hist[2 * TestProcess.getServiceTime().count()];
    }
    for (auto p : hist.toStdMap())
    {
        qDebug() << fixed << qSetRealNumberPrecision(1) << p.first / 2.0 << '-' << (p.first + 1) / 2.0 << ' '
                 << QString(p.second / 150, '*');
    }
}

void TestLoadGen::HistogramOfArrivaltime()
{
    QMap<int, int> hist;
    for (int n = 0; n < 10000; ++n)
    {
        ++hist[TestProcess.getArrivalTime().count()];
    }

    for (auto& d : hist.toStdMap())
    {
        qDebug() << d.first << QString(d.second / 100, '*');
    }

    QVERIFY(!hist.empty());
}

void TestLoadGen::TestTimer()
{
    uint Cnt;
    connect(&TestProcess, &MMProcess::emitNewLoad, [&Cnt](msec_t /*Servicetime*/) { ++Cnt; });
    TestProcess.start();
    for (int i = 0; i < 10000; ++i)
    {
        QCoreApplication::processEvents();
    }
    QVERIFY(Cnt >= 2);
}

QTEST_GUILESS_MAIN(TestLoadGen)

#include "tst_testloadgen.moc"

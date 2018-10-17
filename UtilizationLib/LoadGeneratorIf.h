#ifndef LOADGENERATORIF_H
#define LOADGENERATORIF_H

#include <QObject>
#include <QTimer>

using msec_t = std::chrono::milliseconds;

class LoadGeneratorIf : public QObject
{
    Q_OBJECT
public:
    LoadGeneratorIf(QObject* parent = nullptr);
    virtual ~LoadGeneratorIf() = default;

    virtual msec_t getArrivalTime() = 0;
    virtual msec_t getServiceTime() = 0;

signals:
    void emitNewLoad(msec_t ServiceTime);

public slots:
    void start();
    void stop();

private slots:
    void generateNewLoad();

private:
    QTimer mTimer;
};

#endif  // LOADGENERATORIF_H

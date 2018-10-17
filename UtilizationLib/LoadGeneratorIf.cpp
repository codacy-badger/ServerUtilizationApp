#include "LoadGeneratorIf.h"

LoadGeneratorIf::LoadGeneratorIf(QObject* parent)
  : QObject(parent)
{
    connect(&mTimer, &QTimer::timeout, this, &LoadGeneratorIf::generateNewLoad);
    mTimer.setSingleShot(true);
}

void LoadGeneratorIf::start()
{
    mTimer.start(0);
}

void LoadGeneratorIf::stop()
{
    mTimer.stop();
}

void LoadGeneratorIf::generateNewLoad()
{
    auto NewArrivalTime = getArrivalTime();
    auto NewServiceTime = getServiceTime();
    mTimer.start(NewArrivalTime);
    emit emitNewLoad(NewServiceTime);
}

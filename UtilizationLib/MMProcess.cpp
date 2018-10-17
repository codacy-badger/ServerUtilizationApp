#include "MMProcess.h"

using namespace std;

random_device MMProcess::mRandomDev;
mt19937 MMProcess::mGenerator(mRandomDev());

MMProcess::MMProcess(QObject* parent, msec_t mean_arrival, msec_t mean_service)
  : LoadGeneratorIf(parent)
  , mPoisson(static_cast<int>(mean_arrival.count()))
  , mExpo(static_cast<int>(mean_service.count()))
{
}

msec_t MMProcess::getArrivalTime()
{
    return msec_t(static_cast<int>(mPoisson(mGenerator)));
}

msec_t MMProcess::getServiceTime()
{
    return msec_t(static_cast<int>(mExpo(mGenerator)));
}

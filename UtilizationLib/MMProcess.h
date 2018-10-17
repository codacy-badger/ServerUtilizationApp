#ifndef DEFAULTGENERATOR_H
#define DEFAULTGENERATOR_H

#include "LoadGeneratorIf.h"

#include <random>

class MMProcess : public LoadGeneratorIf
{
    Q_OBJECT
public:
    MMProcess(QObject* parent, msec_t mean_arrival, msec_t mean_service);
    ~MMProcess() override = default;

    msec_t getArrivalTime() override;
    msec_t getServiceTime() override;

private:
    static std::random_device mRandomDev;
    static std::mt19937 mGenerator;
    std::poisson_distribution<> mPoisson;
    std::exponential_distribution<> mExpo;
};

#endif  // DEFAULTGENERATOR_H

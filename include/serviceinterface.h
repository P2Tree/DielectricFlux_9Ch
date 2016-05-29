#ifndef SERVICEINTERFACE_H
#define SERVICEINTERFACE_H

#include "types.h"

class ServiceInterface
{
public:
    ServiceInterface();

    void registerSystemTimer();
    void setSystemTimerId(TimerId_t const);
    void setSystemTimerCount(TimerCount_t const);
    TimerStatus_t getSystemTimerRegisterOn();
    TimerId_t getSystemTimerRegisterId();
    TimerCount_t getSystemTimerRegisterCount();

private:
    /// Heart beat clock: system 1s timer
    static TimerStatus_t systemTimerRegisterOn;
    static TimerId_t systemTimerRegisterId;
    static TimerCount_t systemTimerRegisterCount;
};

#endif // SERVICEINTERFACE_H

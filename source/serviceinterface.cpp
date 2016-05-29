#include "serviceinterface.h"

ServiceInterface::ServiceInterface()
{
}

// identify static arguments in serviceinterface
TimerStatus_t ServiceInterface::systemTimerRegisterOn = TimerOver;
TimerId_t ServiceInterface::systemTimerRegisterId = 0;
TimerCount_t ServiceInterface::systemTimerRegisterCount = 0;

void ServiceInterface::registerSystemTimer() {
    ServiceInterface::systemTimerRegisterOn = TimerRun;
}

void ServiceInterface::setSystemTimerId(TimerId_t const timerId) {
    ServiceInterface::systemTimerRegisterId = timerId;
}

void ServiceInterface::setSystemTimerCount(const TimerCount_t timerCount) {
    ServiceInterface::systemTimerRegisterCount = timerCount;
}

TimerStatus_t ServiceInterface::getSystemTimerRegisterOn() {
    return ServiceInterface::systemTimerRegisterOn;
}

TimerId_t ServiceInterface::getSystemTimerRegisterId() {
    return ServiceInterface::systemTimerRegisterId;
}

TimerCount_t ServiceInterface::getSystemTimerRegisterCount() {
    return ServiceInterface::systemTimerRegisterCount;
}

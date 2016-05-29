#include "timerservice.h"

#include "types.h"
#include "serviceinterface.h"

#include <QTimer>
#include <QMessageBox>
#include <QWidget>
#include <QDebug>

TimerService::TimerService() : systemTimerCycle(1000), timerCount(0)
{
    timer = new QTimer(this);
}

void TimerService::startSystemTimer() {
    connect(timer, SIGNAL(timeout()), this, SLOT(system1sTimeover()));
    timer->start(1000);
    timerId = timer->timerId();
    ServiceInterface serviceInterface;
    serviceInterface.registerSystemTimer();
    serviceInterface.setSystemTimerId(timerId);
}

void TimerService::startTimer(u32_t const timerCycle) {
    connect(timer, SIGNAL(timeout()), this, SLOT(system1sTimeover()));
    timer->start(timerCycle);
}

void TimerService::stopTimer() {
    this->stop();
}

void TimerService::restartTimer() {
    this->start();
}

void TimerService::setTimerCycle(u32_t const time) {
    timerCycle = time;
}

u32_t TimerService::getTimerCycle() {
    return timerCycle;
}

u32_t TimerService::getTimerCount() {
    return timerCount;
}

// slots function
void TimerService::system1sTimeover() {
    timerCount = timerCount + 1;
    qDebug() << "timerCount" << this->timerCount;
    qDebug() << "timerId" << timer->timerId();
    ServiceInterface serviceInterface;
    serviceInterface.setSystemTimerCount(timerCount);
}

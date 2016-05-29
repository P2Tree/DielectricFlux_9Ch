#ifndef TIMERSERVICE_H
#define TIMERSERVICE_H

#include "types.h"
#include <QTimer>

class QTimer;
class QTimerEvent;
class QDebug;

class TimerService : public QTimer
{
    Q_OBJECT
public:
    TimerService();

    void startSystemTimer();
    void startTimer(u32_t const time);

    void stopTimer();
    void restartTimer();
    void setTimerCycle(u32_t const time);
    TimerCount_t getTimerCycle();
    TimerCount_t getTimerCount();

private:
    // about systemTimer
    const u32_t systemTimerCycle;

    // about normal timer
    QTimer *timer;

    TimerId_t timerId;
    TimerCount_t timerCycle;
    TimerCount_t timerCount;

private slots:
    void system1sTimeover(void);
};

#endif // TIMERSERVICE_H

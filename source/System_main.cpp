/**
  * \file	System_main
  * \brief	Basic main Enter of Project
  * \author	Yang Liuming <dicksonliuming@gmail.com>
  * \author Li Haotian <>
  * \version	V1.0
  * \date	2016-5
  *
  ******************************************************/

#include "System_main.h"

#include "types.h"
#include "bottomwindow.h"
#include "windowinterface.h"
#include "timerservice.h"
#include "serviceinterface.h"

void System_main() {
    try {
        /// TODO(Yang Liuming) PoweroffRecoveryCheck
        // if PoweroffRecoveryCheck is off
        System_initialization();
        // if PoweroffRecoveryCheck is on
        // add recovery code
    }
    catch(exception_t) {
    }
}

void System_initialization() {

    // device service initialization
    ServiceInterface *serviceInterface = new ServiceInterface;

    // message queue initialization

    // timer service initialization
    /// system timer is 1 second timer
    TimerService *systemTimer = new TimerService;
    systemTimer->startSystemTimer();

    // system file initialization

    // reading boot file and initialize system variables

    // window initialization
    /// Initialization all needed window, it always upload Bottomwindow and standbywindow.
    /// An interface of window is set.
    WindowInterface windowInterface;
    windowInterface.createWindow(StandbyFlag);


}


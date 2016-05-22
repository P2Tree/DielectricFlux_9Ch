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

    // timer service initialization

    // message queue initialization

    // system file initialization

    // reading boot file and initialize system variables

    /// Initialization all needed window, it always upload buttomwindow and standbywindow.
    /// An interface of window is set.
    WindowInterface windowInterface;
    windowInterface.showWindow();


}


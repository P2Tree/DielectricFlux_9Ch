/**
  * \file	System_main
  * \brief	Basic main Enter of Project
  * \author	Yang Liuming <dicksonliuming@gmail.com>
  * \version	V1.0
  * \date	2016-5
  *
  ******************************************************/

#include "System_main.h"

void System_main() {
    try {
        /// TODO(Yang Liuming) PoweroffRecoveryCheck
        /// TODO(Yang Liuming) if PoweroffRecoveryCheck is off
        System_initialization();
        /// TODO(Yang Liuming) if PoweroffRecoveryCheck is on
    }
    catch(exception_t) {
    }
}

void System_initialization() {

    /// Initialization all needed window, it always upload buttomwindow and standbywindow.
    /// An interface of window is set.
    WindowInterface windowInterface;
    windowInterface.showWindow();


}


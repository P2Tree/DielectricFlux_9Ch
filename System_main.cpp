/**
  * \file	System_main.cpp
  * \brief	Basic main Enter of Project
  * \author	Yang Liuming <dicksonliuming@gmail.com>
  * \version	V1.0
  * \date	2016-5
  *
  ******************************************************/

#include "System_main.h"
#include "types.h"

void System_main() {
    System_setup();
    for(;;)
        System_loop();
}

void System_setup(){
    try {
        ///TODO(Yang Liuming) PoweroffRecoveryCheck
       System_initialization();
    }
    catch(exception_t) {

    }
}

void System_loop() {
    try {
        System_baseMessageQueueCheck();
    }
    catch(int) {

    }
}

void System_initialization() {

}

void System_baseMessageQueueCheck() {

}

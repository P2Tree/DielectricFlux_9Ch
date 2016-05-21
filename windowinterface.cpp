/**
  * \file   WindowInterface
  * \brief  This file is used to supply an interface of window calling and use
            and the interface is windowinterface
  * \author PWE(Yang Liuming) <dicksonliuming@gmail.com>
  * \version    v1.0
  * \date   2016-5
  *
  *********************************************************/
#include "windowinterface.h"

#include "buttomwindow.h"
#include "standbywindow.h"

WindowInterface::WindowInterface()
{
    //buttomWindow = new ButtomWindow;
    standbyWindow = new StandbyWindow;
}

void WindowInterface::showWindow() {
    standbyWindow->show();
}

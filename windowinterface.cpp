/**qt
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
#include "debugwindow.h"

WindowFlag WindowInterface::currentWindowFlag = StandbyFlag;

WindowInterface::WindowInterface()
{
    //buttomWindow = new ButtomWindow;
#if (DebugModE == OpenDebug)
    debugWindow = new DebugWindow;
    changeCurrentWindow(DebugFlag);
#else
    /// typically, without DEBUG mode, standby window is always default window
    standbyWindow = new StandbyWindow;
    changeCurrentWindow(StandbyFlag);
#endif
}

void WindowInterface::showWindow() {
#if (DebugModE == OpenDebug)
    debugWindow->show();
#else
    standbyWindow->show();
#endif
}

void WindowInterface::changeCurrentWindow(WindowFlag const flag) {
    WindowInterface::currentWindowFlag = flag;
}

WindowFlag WindowInterface::getCurrentWindow() {
    return WindowInterface::currentWindowFlag;
}

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

#include "bottomwindow.h"
#include "standbywindow.h"
#include "debugwindow.h"
#include "types.h"

WindowFlag WindowInterface::currentWindowFlag = StandbyFlag;

WindowInterface::WindowInterface() : ShowDebugWindoW(BOOTDEBUG)
{
}

void WindowInterface::constructureWindow(WindowFlag targetWindow) {
    if (ShowDebugWindoW== OpenDebug) {
        debugWindow = new DebugWindow;
        changeCurrentWindowFlag(DebugFlag);
        debugWindow->show();
    }
    else
    {
        switch (targetWindow) {
        case StandbyFlag :
            /// typically, without DEBUG mode, standby window is always default window
            standbyWindow = new StandbyWindow;
            changeCurrentWindowFlag(StandbyFlag);
            standbyWindow->show();
            break;
        default :
            // targetWindow error!
            break;
        }
    }
}

void WindowInterface::changeCurrentWindowFlag(WindowFlag const flag) {
    WindowInterface::currentWindowFlag = flag;
}

WindowFlag WindowInterface::getWindowFlag() {
    return currentWindowFlag;
}

bool WindowInterface::changeWindow(WindowFlag targetWindow,
                                   BottomWindow *const originWindow,
                                   bool const isOriginWindowClose) {
    WindowFlag windowFlag = getWindowFlag();
    WindowFlag originWindowFlag = originWindow->getCurrentWindowFlag();
    if (windowFlag != originWindowFlag)
        // It means that this function called not right,
        // originWindow must be current window.
        return 1;
    if (windowFlag == targetWindow)
        // It means that this function called not right,
        // originWindow must be different with targetWindow.
        return 1;

    createWindow(targetWindow);
    return 0;
}

void WindowInterface::createWindow(WindowFlag targetWindow) {
    constructureWindow(targetWindow);
}

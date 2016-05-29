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

WindowFlag_t WindowInterface::currentWindowFlag = StandbyFlag;

WindowInterface::WindowInterface() : ShowDebugWindoW(BOOTDEBUG)
{
}

void WindowInterface::constructureWindow(WindowFlag_t targetWindow) {
    if (ShowDebugWindoW == OpenDebug) {
        debugWindow = new DebugWindow;
        changeCurrentWindowFlag(DebugFlag);
        debugWindow->show();
    }
    else
    {
        constructureWindowWithoutDebug(targetWindow);
    }
}

void WindowInterface::constructureWindowWithoutDebug(WindowFlag_t const targetWindow) {
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

void WindowInterface::changeCurrentWindowFlag(WindowFlag_t const flag) {
    WindowInterface::currentWindowFlag = flag;
}

WindowFlag_t WindowInterface::getWindowFlag() {
    return currentWindowFlag;
}

void WindowInterface::destructureWindow(BottomWindow *const window) {
    window->close();
}

ReturnStatus_t WindowInterface::changeWindow(WindowFlag_t targetWindow,
                                   BottomWindow *const originWindow,
                                   WindowStatus_t const isOriginWindowClose) {
    WindowFlag_t windowFlag = getWindowFlag();
    WindowFlag_t originWindowFlag = originWindow->getCurrentWindowFlag();
    if (windowFlag != originWindowFlag)
        // It means that this function called not right,
        // originWindow must be current window.
        return Error1;
    if (windowFlag == targetWindow)
        // It means that this function called not right,
        // originWindow must be different with targetWindow.
        return Error1;

    constructureWindowWithoutDebug(targetWindow);
    if (isOriginWindowClose == Close)
        destructureWindow(originWindow);
    return Done;
}

void WindowInterface::createWindow(WindowFlag_t targetWindow) {
    constructureWindow(targetWindow);
}

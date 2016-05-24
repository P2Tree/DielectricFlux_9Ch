#ifndef WINDOWINTERFACE_H
#define WINDOWINTERFACE_H

//#include "standbywindow.h"
//#include "debugwindow.h"
#include "types.h"

class StandbyWindow;
class DebugWindow;
class BottomWindow;

class WindowInterface
{
public:
    WindowInterface();

    WindowFlag getWindowFlag();
    bool changeWindow(WindowFlag const targetWindow,
                      BottomWindow *const originWindow,
                      bool const isOriginWindowClose);
    void createWindow(WindowFlag const targetWindow);
private:
    //BottomWindow *BottomWindow;
    StandbyWindow *standbyWindow;
    DebugWindow *debugWindow;

    /// this argument: currentWindowFlag, is not equal with currentWindowFlag
    /// in other window class. It will be changed when window changed,
    /// you can regard it as a pine to window.
    /// By the way, in other window, currentWindwoFlag is const argument
    static WindowFlag currentWindowFlag ;//= StandbyFlag;

    /// This argument will control the show or hide of debug window.
    /// If argument == OpenDebug, debug window will be always showed
    /// in every boot of the application.
    const debug_t ShowDebugWindoW;

    void constructureWindow(WindowFlag const);
    void changeCurrentWindowFlag(WindowFlag const);
};

#endif // WINDOWINTERFACE_H

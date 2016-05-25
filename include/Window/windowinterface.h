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
    ReturnStatus changeWindow(WindowFlag const targetWindow,
                      BottomWindow *const originWindow,
                      WindowStatus const isOriginWindowClose);
    void createWindow(WindowFlag const targetWindow);
private:
    /* data member */
    StandbyWindow *standbyWindow;
    DebugWindow *debugWindow;

    /* special data member */
    /// this argument: currentWindowFlag, is not equal with currentWindowFlag
    /// in other window class. It will be changed when window changed,
    /// you can regard it as a pine to window.
    /// By the way, in other window, currentWindwoFlag is const argument
    static WindowFlag currentWindowFlag ;//= StandbyFlag;

    /// This argument will control the show or hide of debug window.
    /// If argument == OpenDebug, debug window will be always showed
    /// in every boot of the application.
    const debug_t ShowDebugWindoW;

    /* member function */
    /**
      * \brief  this function is used to change flag with window changed
      * \brief  when window changed, this functino must be called.
      */
    void changeCurrentWindowFlag(WindowFlag const);

    /**
      * \brief  this function can constructure window, if DebugModE is
      *         set in types.h, this function will always open debug window
      */
    void constructureWindow(WindowFlag const);

    /**
      * \brief  this function can constructure window and don't check
      *         DebugModE, can not open debug window.
      * \brief  Compare with constructureWindow.
      */
    void constructureWindowWithoutDebug(WindowFlag const);

    /**
      * \brief  this function can destructure window.
      */
    void destructureWindow(BottomWindow *const window);
};

#endif // WINDOWINTERFACE_H

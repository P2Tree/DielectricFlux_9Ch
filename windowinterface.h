#ifndef WINDOWINTERFACE_H
#define WINDOWINTERFACE_H

#include "buttomwindow.h"

class ButtomWindow;

class WindowInterface
{
public:
    WindowInterface();

    void showWindow(void);

private:
    ButtomWindow *buttomWindow;
};

#endif // WINDOWINTERFACE_H

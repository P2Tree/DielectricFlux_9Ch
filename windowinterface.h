#ifndef WINDOWINTERFACE_H
#define WINDOWINTERFACE_H


class ButtomWindow;
class StandbyWindow;
class DebugWindow;

enum WindowFlag {
    StandbyFlag,
    DebugFlag
};

class WindowInterface
{
public:
    WindowInterface();

    void showWindow(void);

    void changeCurrentWindow(WindowFlag const);
    WindowFlag getCurrentWindow(void);

private:
    //ButtomWindow *buttomWindow;
    StandbyWindow *standbyWindow;
    DebugWindow *debugWindow;
    static WindowFlag currentWindowFlag;
};

#endif // WINDOWINTERFACE_H

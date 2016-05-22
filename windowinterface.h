#ifndef WINDOWINTERFACE_H
#define WINDOWINTERFACE_H


class ButtomWindow;
class StandbyWindow;

enum WindowFlag {
    StandbyFlag
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

    static WindowFlag currentWindowFlag;
};

#endif // WINDOWINTERFACE_H

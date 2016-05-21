#ifndef WINDOWINTERFACE_H
#define WINDOWINTERFACE_H


class ButtomWindow;
class StandbyWindow;

class WindowInterface
{
public:
    WindowInterface();

    void showWindow(void);

private:
    //ButtomWindow *buttomWindow;
    StandbyWindow *standbyWindow;
};

#endif // WINDOWINTERFACE_H

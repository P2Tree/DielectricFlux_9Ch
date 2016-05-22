#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include "buttomwindow.h"

/// debug flag type
enum debug_t {
    OpenDebug,
    CloseDebug
};

class QPushButton;
class QString;

class DebugWindow : public ButtomWindow
{
    Q_OBJECT

public:
    DebugWindow();

    /// debug button can not only show in debug window, but can show in normal
    /// window if you want to open debug message box. use this function.

private:
    void debugMessageBox(DebugWindow *const);
    void setupMainLayout();
    void setupButtonLayout();
    QString debugWindowTitle;
    QLabel *debugMainDeclare;
    QPushButton *debugButton;

    /// DebugModE is so important that without DebugModE=DEBUG, no DebugWindow
    /// object can be complete constructed.
    static const debug_t DebugModE = OpenDebug;

public slots:
    void debugButtonClicked();
};

#endif // DEBUGWINDOW_H

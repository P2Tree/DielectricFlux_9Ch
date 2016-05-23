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
    /// TODO (Yang Liuming) <dicksonliuming@gmail.com>
private:
    void debugMessageBox(DebugWindow *const);
    void debugMessageBox(DebugWindow *const, QString const);
    void setupMainLayout();
    void setupButtonLayout();
    QString debugWindowTitle;
    QLabel *debugMainDeclare;
    QPushButton *debugButton;

    /// DebugModE is so important that without DebugModE=DEBUG, no DebugWindow
    /// object can be complete constructed.
    static const debug_t DebugModE = OpenDebug;

    /**
      * \brief  translate the window
      */
    void retranslateUi(DebugWindow *const);

public slots:

    /**
      * \brief  triggered when debugbutton was clicked. slot function.
      */
    void debugButtonClicked();
};

#endif // DEBUGWINDOW_H

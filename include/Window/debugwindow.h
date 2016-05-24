#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include "bottomwindow.h"
#include "types.h"

class QPushButton;
class QString;


class DebugWindow : public BottomWindow
{
    Q_OBJECT

public:
    DebugWindow();

    /**
      * \brief  this function can get window flag of its window.
      */
    WindowFlag getCurrentWindowFlag(void);
protected:
    // I move the DebugModE in types.h file.
    //const debug_t DebugModE;//DEBUG;

private:
    void setupMainLayout(void);
    void setupButtonLayout(void);

    QString debugWindowTitle;
    QLabel *debugMainDeclare;

    /// debug button can not only show in debug window, but can show in normal
    /// window if you want to open debug message box.
    /// Another const argument: DebugModE in types.h can control this.
    QPushButton *debugButton;

    QPushButton *returnButton;

    WindowFlag const currentWindowFlag;

    void debugMessageBox(DebugWindow *const);
    void debugMessageBox(DebugWindow *const, QString const);
    /**
      * \brief  translate the window
      */
    void retranslateUi(DebugWindow *const);


public slots:
    void debugButtonClicked(void);
    //void returnButtonClicked(void);
};

#endif // DEBUGWINDOW_H

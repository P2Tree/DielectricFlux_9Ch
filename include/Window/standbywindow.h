#ifndef STANDBYWINDOW_H
#define STANDBYWINDOW_H

#include "bottomwindow.h"
#include "windowinterface.h"

class QLabel;
class QPushButton;
class QString;
//class BottomWindow;

class StandbyWindow : public BottomWindow
{
    Q_OBJECT

public:
    StandbyWindow();

    WindowFlag_t getCurrentWindowFlag(void);
private:
    QString standbyWindowTitle;
    QLabel *standbyMainDeclare;
    QPushButton *standbyButtonStart;
    QPushButton *standbyButtonFile;
    QPushButton *standbyButtonSetup;
    QPushButton *standbyButtonAbout;
    QPushButton *debugButton;

    WindowFlag_t const currentWindowFlag;
    /**
      * \brief  rewrite the draw function
      */
    void setupMainLayout(void);
    void setupButtonLayout(void);

    void debugMessageBox(BottomWindow *const, QString const);
    void setupDebugDialog(BottomWindow *const);
    /**
      * \brief  translate the window
      */
    void retranslateUi(StandbyWindow *const);

public slots:
    void debugButtonClicked(void);
};

#endif // STANDBYWINDOW_H

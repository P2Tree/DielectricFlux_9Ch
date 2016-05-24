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

    WindowFlag getCurrentWindowFlag(void);
private:
    QString standbyWindowTitle;
    QLabel *standbyMainDeclare;
    QPushButton *standbyButtonStart;
    QPushButton *standbyButtonFile;
    QPushButton *standbyButtonSetup;
    QPushButton *standbyButtonAbout;
    QPushButton *debugButton;

    WindowFlag const currentWindowFlag;
    /**
      * \brief  rewrite the draw function
      */
    void setupMainLayout(void);
    void setupButtonLayout(void);

    void debugMessageBox(StandbyWindow *const);
    void debugMessageBox(StandbyWindow *const, QString const);
    /**
      * \brief  translate the window
      */
    void retranslateUi(StandbyWindow *const);

public slots:
    void debugButtonClicked(void);
};

#endif // STANDBYWINDOW_H
